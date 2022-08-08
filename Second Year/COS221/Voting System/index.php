<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./css/header.css" />
    <link rel="stylesheet" href="./css/addressupdate.css" />
    <title>Home page</title>
</head>
<body>
    
    <?php

    /*
    session_start();
    $_SESSION['worker'] = true;
    $_SESSION['name'] = 'muzi';
    */

        include 'header.php';
        include 'navbar.php';
        if (isset($_GET['page'])) {
            $page = $_GET['page'];
            if (isset($_SESSION['worker'])) {
                //Logged in currently as an iec worker
                switch ($page) {
                    case 'validatevoters':
                        include './user_iec/validatevoters.php';
                        die();
                    case 'capturepartyinfo':
                        include './user_iec/capturepartyinfo.php';
                        die();
                    case 'extractreports':
                        include './user_iec/extractreports.php';
                        die();
                }
                echo 'Link tampering detected and blocked.';
                die();
            }
            else {
                //logged in currently as a voter
                switch ($page) {
                    case 'castvote':
                        include './user_std/castvote.php';
                        die();
                    case 'updateaddress':
                        include './updateaddressform.php';
                        die();
                }
                echo 'Link tampering detected and blocked.';
                die();
            }
            die();
        }
        include 'home.php';
    ?>
</body>
</html>