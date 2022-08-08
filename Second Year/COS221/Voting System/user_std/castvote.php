<?php

    if (isset($_SESSION['voted'])) {
        if ($_SESSION['voted'] == true) {
            echo '<h1 style="text-align:center;">THANK YOU FOR CASTING YOUR VOTE</h1>';
            die();
        }
    }

    echo '<div id="castvote">';
    echo '<div id="inputs">';
    echo '<form name="signupform" onsubmit="return sign_click()" action ="validate_vote.php"  method="POST">';
    //sign up inputs:
    require_once "config.php";
    if(isset($_SESSION['areacode'])){
        $areacode = $_SESSION['areacode'];
    }

    $sql = "SELECT * FROM metro where area_code='$areacode'";
    $result = mysqli_query($conn, $sql);
	if ( $result->fetch_assoc()) {
        echo '<h1>Metro Vote</h1>';
        echo "<h3> Your Metro: ".$areacode."</h3>";
        echo '<select id="ethnicity" name="metrovote" class="inputbox">';
        /*
        METRO
        echo <option>
        name to choose
        echo </option>
        */
       
        $sql = "SELECT * FROM party";
            $result = mysqli_query($conn, $sql);
            while($row = mysqli_fetch_assoc($result)) {
                ?>
                <tr>
                            <option><?php echo $row['name'] ?></option>
                    </tr>
                <?php
            }
        
        echo '</select>';
    }
    $sql = "SELECT * FROM local where area_code='$areacode'";
    $result = mysqli_query($conn, $sql);
	if ( $result->fetch_assoc()) {
        echo '<h1>Local Vote</h1>';
        echo "<h3> Your Local Municipality: ".$areacode."</h3>";
        echo '<select id="ethnicity" name="localvote" class="inputbox">';
        /*
        LOCAL
        echo <option>
        name to choose
        echo </option>
        */
        $sql = "SELECT * FROM party";
        $result = mysqli_query($conn, $sql);
        while($row = mysqli_fetch_assoc($result)) {
            ?>
            <tr>
                        <option><?php echo $row['name'] ?></option>
                </tr>
            <?php
        }
        echo '</select>';
    }

    echo '<input type ="submit" value="CAST YOUR VOTE" name="submit" class="button" >';
    echo '</div>';
    echo '</div>';

    echo '</form>';
    echo '</div>';
    echo '</div>';
