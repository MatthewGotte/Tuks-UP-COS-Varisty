<?php
    @session_start();
    //Check if worker:
    if (isset($_SESSION['worker'])) {
        if ($_SESSION['worker'] == true) {
            //check on these pages is the $_SESSION is set for worker to prevent URL tampering:
            echo '<nav class="navbar">';
            echo '<a class="navbar-item" href="./index.php">HOME</a>';
            echo '<a class="navbar-item" href="./index.php?page=validatevoters">VALIDATE VOTERS</a>';
            echo '<a class="navbar-item" href="./index.php?page=capturepartyinfo">CAPTURE PARTIES</a>';
            echo '<a class="navbar-item" href="./index.php?page=extractreports">EXTRACT REPORTS</a>';
            echo '<a class="navbar-item">IEC: ' . @$_SESSION['name'] . '</a>';
            echo '<a class="navbar-item" href="./logout.php">LOG OUT</a>';
            echo '</nav>';
        }
    }
    //Check if voter:
    if (isset($_SESSION['voter'])) {
        if ($_SESSION['voter'] == true) {
        // else if (true) {
        //     if (true) {
            echo '<nav class="navbar">';
            echo '<a class="navbar-item" href="./index.php">HOME</a>';
            echo '<a class="navbar-item" href="./index.php?page=castvote">CAST VOTE</a>';
            echo '<a class="navbar-item" href="./index.php?page=updateaddress">UPDATE ADDRESS</a>';
            echo '<a class="navbar-item" href="./index.php">VOTER: ' . @$_SESSION['name'] . '</a>';
            echo '<a class="navbar-item" href="./logout.php">LOG OUT</a>';
            echo '</nav>';
        }
    }

    else if ((!isset($_SESSION['worker'])) && (!isset($_SESSION['voter']))) {
        echo '<nav class="navbar">';
        echo '<a class="navbar-item" href="./index.php">HOME</a>';
        echo '<a class="navbar-item" href="./login.php">LOG IN</a>';
        echo '<a class="navbar-item" href="./signup.php">REGISTER</a>';
        echo '</nav>';
    }


    //not a worker, echo std user navbar
    //check on these pages is the $_SESSION is set for user to prevent URL tampering:
    
?>