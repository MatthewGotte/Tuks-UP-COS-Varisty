<h1 class="title" id="listtitle">Current list of parties</h1>

<div id="addparty">
    <div id="inputs">
        <h3>Add a new party</h3>
        <form method="POST" action="addparty.php">
            <input id="name" class="inputbox" name="name" type="text" placeholder="Name"/>
            <input id="leader" class="inputbox" name="leader" type="text" placeholder="Leader"/>
            <input id="members" class="inputbox" name="members" type="text" placeholder="Number of Members"/>
            <input type="submit" class="button" name="update" value="Update">
        </form>
    </div>
</div>

<table border="1" id="partytable">
    <tr>
            <td>Name</td>
            <td>Leader</td>
            <td>Number of Members</td>
    </tr>
    <?php
        require_once "config.php";
        $sql = "SELECT * FROM party";
        $result = mysqli_query($conn, $sql);
        while($row = mysqli_fetch_assoc($result)) {
            ?>
            <tr>
                        <td><?php echo $row['name'] ?></td>
                        <td><?php echo $row['leader']?></td>
                        <td><?php echo $row['num_members']?></td>
                </tr>
            <?php
        }
    ?>
</table>

