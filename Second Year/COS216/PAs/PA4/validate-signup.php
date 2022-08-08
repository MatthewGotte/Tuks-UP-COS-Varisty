<?php
    /*
    header ("Location: trending.php");
    exit();
    */
    require_once 'header.php';

    DEFINE ('BR', '<br />');

    if (exists($dbc, $_POST['email'])) {
        alreadyExists();
        return;
    }

    echo 'user is being registered...';

    $p_name = $_POST['name'];
    $p_surname = $_POST['surname'];
    $p_email = $_POST['email'];
    $p_password = $_POST['password'];


    addUser($dbc, $p_name, $p_surname, $p_email, hashpass($p_password, $p_email), generateAPI_key($p_email));

    function exists($dbc,$email) {
        $query = 'SELECT * FROM users WHERE email="' . $email . '";';
        //echo BR . $query . BR;
        $response = @mysqli_query($dbc, $query);
        $row = mysqli_fetch_array($response);
        if ($row == null) return false;
        return true;
    }

    function hashpass($password, $p_email) {
        return md5($password . strrev($p_email));
    }

    function addUser($dbc, $name, $surname, $email, $pass, $API_key) {
        $query = 'INSERT INTO users(id, name, surname, email, password, API_key) VALUES (NULL, ?, ?, ?, ?, ?);';
        $stmt = mysqli_prepare($dbc, $query);
        mysqli_stmt_bind_param($stmt, "sssss", $name, $surname, $email, $pass, $API_key);
        mysqli_stmt_execute($stmt);
        $affected_rows = mysqli_stmt_affected_rows($stmt);
        if ($affected_rows == 1) {
            
            header('Location: login.php');
            exit();

            mysqli_stmt_close($stmt);
        }
        else {
            echo 'error' .BR . mysqli_error();
            mysqli_smt_close($stmt);
        }

    }

    function generateAPI_key($e) {
        $result = md5($e);
        return $result;
    }

    $exists;
    function alreadyExists() {
        $_SESSION['exists'] = true;
        header('Location: signup.php');
        exit();
    }

?>