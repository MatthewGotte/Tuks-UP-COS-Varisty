<?php
require_once "config.php"; 
if(isset($_POST['id'])){
    $id = $_POST['id'];
    $sql = "UPDATE reg_person SET validated = 1 WHERE id='$id' ";
    
    if ($conn->query($sql) === TRUE) {
        header("location: index.php?page=validatevoters");
      } else {
        echo "Error updating record: " . $conn->error;
      }
      
}
else{
    header("location: index.php?page=validatevoters?error=unkownerror");
}
?>