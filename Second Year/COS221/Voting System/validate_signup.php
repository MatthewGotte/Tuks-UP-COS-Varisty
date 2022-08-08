<?php 
session_start(); 
require_once "config.php";
if( isset($_POST['fname']) && 
	isset($_POST['surname']) &&
	isset($_POST['initials']) &&
	isset($_POST['id']) && 
	isset($_POST['email']) &&
	isset($_POST['contact'])&&
	isset($_POST['address'])&&
	isset($_POST['areacode'])&&
	isset($_POST['ethnicity']) &&
	isset($_POST['password1']) &&
	isset($_POST['sex']) 
	)
	{

	function validate($data){
        $data = trim($data);
	    $data = stripslashes($data);
	    $data = htmlspecialchars($data);
	   return $data;
	}
	$fname = validate($_POST['fname']);
	$lname = validate($_POST['surname']);
	$minit = validate($_POST['initials']);
	$id =validate($_POST['id']) ;
	$e_mail =validate($_POST['email'])  ;
	$cell_no =validate($_POST['contact']);
	$address = validate($_POST['address']);
	$areacode = validate($_POST['areacode']);
	$ethnicity = validate($_POST['ethnicity']);
	$sex = validate($_POST['sex']); 
	$password = validate($_POST['password1']) ;

	//adding the salt to the password.
	$salt = md5($id);
	$password .=$salt;
	$pass = md5($password);
	
	$sql = "SELECT * 
			FROM reg_person
			WHERE id ='$id' ";
	$result = mysqli_query($conn, $sql);
	if ( $result->fetch_assoc()) {
    	function error() {
       	 	$_SESSION['exists'] = true;
        	header('Location: signup.php?error=exists');
        	exit();
    	}
		error();
	}else {
		$sql2 = "INSERT INTO reg_person (id,fname,minit,lname,address,area_code,e_mail,cell_no,ethnicity,sex,password) 
		VALUES('$id','$fname','$minit','$lname','$address','$areacode','$e_mail','$cell_no','$ethnicity','$sex','$pass')";
		$result2 = mysqli_query($conn, $sql2);
		if(!$result2){
			function error() {
				$_SESSION['exists'] = true;
				header('Location: signup.php?error=server_error');
				exit();
    		}
			error();
		}
		else{
			header('Location: login.php');
		}
	}
}
else{
	header("Location: login.php?error=server_error");
	exit();
}
?>