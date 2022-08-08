<?php
echo '<div id="addresschange">';
    echo '<div id="inputs">';
    echo '<form name="updateaddresRs" action ="./user_std/updateaddress.php" method="POST">';
            //log in inputs:
            echo '<input id="id" class="inputbox" name="id" type="text" placeholder="SA ID Number"/>';
            echo '<input id="name" class="inputbox" name="name" type="text" placeholder="Name"/>';
            echo '<input id="newaddress" class="inputbox" name="newaddress" type="text" placeholder="New Address"/>';
            echo '<input id="reasonmove" class="inputbox" name="reasonmove" type="text" placeholder="Reason for move"/>';
            echo '<input type="submit" name ="iecsubmit" value="SUBMIT NEW ADDRESS" class="button">';
    echo '</form>';
    echo '</div>';
echo '<div>';