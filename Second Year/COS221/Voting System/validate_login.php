<?php 
require_once "config.php";

if (isset($_POST['password']) && isset($_POST['id']) ) {
	function validate($data){
        $data = trim($data);
	    $data = stripslashes($data);
	    $data = htmlspecialchars($data);
	   return $data;
	}

	$password = validate($_POST['password']);
    $id = validate($_POST['id']);
	$salt = md5($id);
	$password .= $salt;
	$pass = md5($password);
	
	$sql = "SELECT * FROM reg_person WHERE id='$id' ";
	$result = mysqli_query($conn, $sql);
	
	if (mysqli_num_rows($result) === 1) {
		$row = mysqli_fetch_assoc($result);
		if ($row['id'] === $id && $row['password'] === $pass) {
			session_start();
			$_SESSION['id'] = $row['id'];
			$_SESSION['areacode'] = $row['area_code'];
			$_SESSION['name'] = $row['fname'];
			$_SESSION['voter'] = true;
			$_SESSION['voted'] = $row['voted'];
			header("Location: index.php");
			exit();
		}else{
			header("Location: login.php?error=failed");
			exit();
		}
		exit();
	}else {        
			header("Location: login.php?error=failed");
			exit();
	}
}
else{
	header("Location: login.php?error=failed");
	exit();
}