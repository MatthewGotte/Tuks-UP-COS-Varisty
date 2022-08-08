<h1 id="title">VOTERS PENDING APPROVAL</h1>
<link rel="stylesheet" href="css/validatevoters.css">

<table border="1" id="validatevotertable">
  <tr>
        <td>Identy number </td>
        <td>First name</td>
        <td>Initials</td>
        <td>Last Name</td>
        <td>Address</td>
ode</td>
        <td>Email</td>
        <td>Cell_no</td>
        <td>Ethnicity</td>
        <td>Sex</td>   
  </tr>
<?php
    require_once "config.php";
    $sql = "SELECT * FROM reg_person WHERE validated='0' ";
    $result = mysqli_query($conn, $sql);
    while($row = mysqli_fetch_assoc($result)) {
        ?>
        <tr>
                    <td><?php echo $row['id'] ?></td>
                    <td><?php echo $row['fname']?></td>
                    <td><?php echo $row['minit']?></td>
                    <td><?php echo $row['lname']?></td>
                    <td><?php echo $row['address']?></td>
                    <td><?php echo $row['area_code']?></td>
                    <td><?php echo $row['e_mail']?></td>
                    <td><?php echo $row['cell_no']?></td>
                    <td><?php echo $row['ethnicity']?></td>
                    <td><?php echo $row['sex']?></td> 
                    <td>
                    <form method="POST" action="update_voter.php">
                        <input id="id" class="inputbox" name="id" type="hidden" value="<?php echo $row['id']?>" />
                        <input type="submit" name="update" value="Update">
                    </form>
                    </td>
            </tr>
        <?php
    }
?>
</table>

