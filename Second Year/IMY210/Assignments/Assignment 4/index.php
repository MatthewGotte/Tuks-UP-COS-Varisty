<?php
	function printer($JSON) {
		$jsonIterator = new RecursiveIteratorIterator(
			new RecursiveArrayIterator(json_decode($JSON, TRUE)),
			RecursiveIteratorIterator::SELF_FIRST);
		foreach ($jsonIterator as $key => $val) {
			if(!is_array($val)) {
				print $key."	:	".$val;
			}
			echo '<br />';
		}
	}

	if (isset($_POST['submit'])){ 
		echo_ret();
		ret_button();

		if (!isset($_POST['actions'])) {
			$output = exec('curl localhost:3000/data');
			if ($output == '{}') {
				die('No data was returned');
			}
			printer($output);
			die();
		}
		$action = $_POST['actions'];
		switch ($action)
		    {
		        case "POST":
						if (isset($_POST['file'])) {
							$target_file = basename($_FILES["object"]["name"]);
							$uploadOk = 1;
							$filetype = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));
							if ($filetype != 'json') {
								echo 'Invalid file type, only submit a .json file.';
								die();
							}
							if (move_uploaded_file($_FILES["object"]["tmp_name"], $target_file)) {
								echo "The file ". htmlspecialchars( basename( $_FILES["object"]["name"])). " has been uploaded.<br /><hr />";
							}
							$content = file_get_contents($target_file);
							if (!json_validator($content)) {
								echo 'An invalid json file was uploaded.';
								die();
							}
							$decoded = json_decode($content);
							foreach($decoded as $temp) {
								//make POST curls here:
								exec('curl localhost:3000/data -H "Content-Type: application/json" -d "{\"name\":\"' . $temp->name . '\",\"price\":\"' . $temp->price . '\"}" ');
							}
							$output = exec('curl localhost:3000/data');
							if ($output == null) {
								die('No data was returned');
							}
							printer($output);
							unlink($target_file);
							die();
						}
						//std_post:
						$name = $_POST['name'];
						$price = $_POST['price'];
						$output = exec('curl localhost:3000/data -H "Content-Type: application/json" -d "{\"name\":\"' . $name . '\",\"price\":\"' . $price . '\"}" ');
						if ($output == null) {
							die('No data was returned');
						}
						printer($output);


		            break;
		        case "PUT":
					$name = $_POST['name'];
					$price = $_POST['price'];
					$id = $_POST['id'];
					$response = exec('curl -X PUT -d name="' . $name . '" -d price="' . $price . '" localhost:3000/data/' . $id);
					if ($response == null) {
						die('No data was returned');
					}
					printer($response);
		            break;
		        case "GET":
					$id = $_POST['id'];
					$response = exec('curl localhost:3000/data/' . $id);
					if ($response == null) {
						die('No data was returned');
					}
					printer($response);
		        break;
		        case "DELETE":
						$id = $_POST['id'];
						$response = exec('curl -X DELETE localhost:3000/data/' . $id);
						if ($response == null) {
							die('No data was returned');
						}
						printer($response);
		        break;
		        default:
		            echo "error";
		    }

	} else {
		nav_bar();
	}

	function json_validator($data=NULL) {
		if (!empty($data)) {
				@json_decode($data);
				return (json_last_error() === JSON_ERROR_NONE);
			  }
			  return false;
	  }

	function ret_button() {
		echo '<button onclick="ret()">Click to go back home.</button>';
		echo '<h1><u>Displaying data from your request:</u></h1>';
	}

	function nav_bar() {
		echo '<h1>Query method:</h1>';
		echo '<button onclick="get()">GET</button>';
		echo '<button onclick="post()">POST</button>';
		echo '<button onclick="update()">UPDATE</button>';
		echo '<button onclick="del()">DELETE</button>';
	}

	function echo_ret() {
		echo '<script>';
		echo 'function ret() {';
		echo 'window.location.href = "index.php";';
		echo '}';
		echo '</script>';
	}
?>

<script>

	function get() {
		hide_all();
		var get = document.getElementById("get_div");
		get.style.display = 'block'; 
	}

	function post() {
		hide_all();
		var post = document.getElementById("post_div");
		post.style.display = 'block';
	}

	function update() {
		hide_all();
		var update = document.getElementById("update_div");
		update.style.display = 'block';
	}

	function del() {
		hide_all();
		var del = document.getElementById("delete_div");
		del.style.display = 'block';
	}

	function hide_all() {
		var get = document.getElementById("get_div");
		get.style.display = 'none';
		var post = document.getElementById("post_div");
		post.style.display = 'none';
		var update = document.getElementById("update_div");
		update.style.display = 'none';
		var del = document.getElementById("delete_div");
		del.style.display = 'none';
	}

	document.addEventListener('DOMContentLoaded', function () {
		hide_all();
	}, false);

</script>

<!--GET-->
<div id="get_div" class="method">
	<h1>GET</h1>
	<h4>Get all available data:</h4>

	<form method="POST" action="index.php">
		<input type="submit" value="submit" name="submit">
	</form>

	<hr />

	<h4>Get data for entry:</h4>

	<form method="POST" action="index.php">
		<input type="text" id="actions" name="actions" style="display: none" value="GET">
		<input type="text" id="id" name="id" placeholder="id"/>
		<br />
		<br />
		<input type="submit" value="submit" name="submit">
	</form>

</div>

<!--POST-->
<div id="post_div" class="method">
	<h1>POST</h1>
	<h4>Adding data for entry via input:</h4>
	<form method="POST" action="index.php">
		<input type="text" id="actions" name="actions" style="display: none" value="POST">
		Name: <input type="text" id="name" name="name" placeholder="name"/>
		<br />
		<br />
		Price: <input type="text" id="price" name="price" placeholder="price"/>
		<br />
		<br />
		<input type="submit" value="submit" name="submit">
	</form>
	<hr/>

	<form action="index.php" method="POST" enctype="multipart/form-data">
		<input type="text" id="actions" name="actions" style="display: none" value="POST">
		<input type="text" id="file" name="file" style="display: none" value="FILE">
		File Upload ( upload a .json file containing one or many json objects to be added via POST ):<br/><br/>
		Select file to upload: <input type="file" name="object" id="object">
		<input type="submit" value="File Upload" name="submit">
	</form>

</div>

<!--UPDATE-->
<div id="update_div" class="method">
	<h1>UPDATE</h1>
	<h4>Data to update during entry:</h4>
	<form method="POST" action="index.php">
		<input type="text" id="actions" name="actions" style="display: none" value="PUT">
		id to update: <input type="text" id="id" name="id" placeholder="id">
		<br />
		<br />
		Name to update to: <input type="text" id="name" name="name" placeholder="name">
		<br />
		<br />
		Price to update to: <input type="text" id="price" name="price" placeholder="price">
		<br />
		<br />
		<input type="submit" value="submit" name="submit">
	</form>
</div>

<!--DELETE-->
<div id="delete_div" class="method">
	<h1>DELETE</h1>
	<h4>Data to delete during entry:</h4>
	<form method="POST" action="index.php">
		<input type="text" id="actions" name="actions" style="display: none;" value="DELETE">
		id to be deleted: <input type="text" id="id" name="id" placeholder="id">
		<br />
		<br />
		<input type="submit" value="submit" name="submit">
	</form>
</div>