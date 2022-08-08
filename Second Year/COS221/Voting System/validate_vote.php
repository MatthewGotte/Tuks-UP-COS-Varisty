<?php 
require_once "config.php";
session_start();
if (isset($_POST['localvote'])){
    $localvote= $_POST['localvote'];
    $_POST['localvote'] = 1;
    $id = $_SESSION['id'];
    $sql = "UPDATE reg_person SET voted='1'  WHERE id = '$id' ";
    mysqli_query($conn , $sql);
   
    $sql2 = "INSERT INTO votes_local (candidate) VALUES ('$localvote')";
	$result = mysqli_query($conn, $sql);
    if(!$result){
        echo "took an L: ";
    }
    else{
        header('Location: index.php');
    }
    //header('location: index.php');

}
else if(isset($_POST['metrovote']) ) {
    $metrovote= $_POST['metrovote'];
    $_POST['metrovote'] = 1;
    $id = $_SESSION['id'];
    $sql = "UPDATE reg_person SET voted='1'  WHERE id = '$id' ";
    mysqli_query($conn , $sql);

    $sql2 = "INSERT INTO votes_metro (candidate) VALUES ('$metrovote')";
    $result = mysqli_query($conn, $sql);
    if(!$result){
        echo "took an L:";
    }
    else{
        header('Location: index.php');
    }
}
else{
	header("Location: user_std/castvote.php?error=failed");
	exit();
}