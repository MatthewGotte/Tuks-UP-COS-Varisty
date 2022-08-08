<?php

    require_once 'header.php';

    DEFINE ('BR', '<br />');

    if (!exists($dbc, $_POST['email'])) {
        error();
        return;
    }
    
    function exists($dbc,$email) {
        $query = 'SELECT * FROM users WHERE email="' . $email . '";';
        $response = @mysqli_query($dbc, $query);
        $row = mysqli_fetch_array($response);
        if ($row == null) return false;
        checksuccess($row);
        return true;
    }

    function checksuccess($row) {
        //echo $row['email'];
        if ($_POST['email'] != $row['email']) {
            error();
            return;
        }
        if (!verify($_POST['password'], $_POST['email'], $row['password'])) {
            error();
            return;
        }

        session_start();
        $_SESSION['name'] = strtoupper($row['name']);
        $_SESSION['API_key'] = $row['API_key'];
        header('Location: trending.php');
        exit();
    }

    function verify($p, $e, $r) {
        if (md5($p . strrev($e)) == $r) return true;
        return false;
    }

    $exists;
    function error() {
        //session_start();
        $_SESSION['exists'] = false;
        header('Location: login.php');
        exit();
    }

?>