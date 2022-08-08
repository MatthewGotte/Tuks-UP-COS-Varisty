<?php 
require_once "config.php";

if (isset($_POST['iecpassword']) && isset($_POST['iecid']) ) {
	function validate($data){
        $data = trim($data);
	    $data = stripslashes($data);
	    $data = htmlspecialchars($data);
	   return $data;
	}

	$iecpassword = validate($_POST['iecpassword']);
    $iecid = validate($_POST['iecid']);
	$salt = md5($iecid);
	$iecpassword .= $salt;
	$pass = md5($iecpassword);
	
	$sql = "SELECT * FROM iec_worker WHERE worker_id='$iecid' ";
	$result = mysqli_query($conn, $sql);
	
	if (mysqli_num_rows($result) === 1) {
		$row = mysqli_fetch_assoc($result);
		if ($row['worker_id'] === $iecid && $row['password'] === $pass) {
            $id = $row['id'];
            $sql2 = "SELECT fname FROM reg_person WHERE id='$id' ";
	        $result2 = mysqli_query($conn, $sql2);
            $row2 = mysqli_fetch_assoc($result2);
            session_start();
            $_SESSION['name'] = $row2['fname'];
			$_SESSION['id'] = $row['worker_id'];
			$_SESSION['worker'] = true;
			header("Location: index.php");
			exit();
		}else{
			header("Location: ieclogin.php?error=failed");
			exit();
		}
		exit();
	}else {        
			header("Location: ieclogin.php?error=failed");
			exit();
	}
}
else{
	header("Location: ieclogin.php?error=failed");
	exit();
}