<?php

require_once '../config.php';

session_start();
if(isset($_SESSION['name']) && isset($_SESSION['id']) && isset($_POST['newaddress']))
{

    $name = $_SESSION['name'] ;
    $id = $_SESSION['id'];
    $newAddress = $_POST['newaddress'];
    $sql = "UPDATE reg_person SET address='$newAddress'  WHERE id = '$id' ";
    mysqli_query($conn , $sql);
   
    $sql = "SELECT address FROM reg_person WHERE id='$id' ";
	$result = mysqli_query($conn, $sql);
    $row = $result->fetch_assoc();
    if($result->fetch_assoc())
    {
    
    }
}
header('Location: ../index.php');


?>
