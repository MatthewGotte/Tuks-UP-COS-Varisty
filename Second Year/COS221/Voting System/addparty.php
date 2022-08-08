<?php
require_once "config.php"; 
if(isset($_POST['name'])&& isset($_POST['leader']) && isset($_POST['members'])){
    $name = $_POST['name'];
    $leader = $_POST['leader'];
    $members = $_POST['members'];
    $sql = "INSERT INTO party (name,leader,num_members)
        VALUES('$name','$leader','$members') ";

    $sql1 = "SELECT * 
    FROM party
    WHERE name ='$name' ";
    $result = mysqli_query($conn, $sql1);
    if ( $result->fetch_assoc()) {
        echo "party already exists";
        exit();
    }
    $sql = "INSERT INTO party (name,leader,num_members)
        VALUES('$name','$leader','$members') ";
    if ($conn->query($sql) === TRUE) {
        header("location: index.php?page=capturepartyinfo");
      } else {
        echo "Error updating record: " . $conn->error;
      }
      
}
else{
    header("location: index.php?page=capturepartyinfo");
}
?>