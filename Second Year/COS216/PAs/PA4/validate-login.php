<?php
    require_once 'header.php';
    DEFINE ('BR', '<br />');
    $email = $_POST['email'];
    $password = $_POST['password'];
    $url = 'http://localhost/COS216/PA4/api.php';
    $ch = curl_init($url);
    $return = array('title', 'score','release');
    $data = array(
        'password' => $password,
        'email'=> $email,
        'type'=>'login',

    );

    $payload = json_encode($data);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $payload);
    curl_setopt($ch, CURLOPT_HTTPHEADER, array('Content-Type:application/json'));
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    $result = curl_exec($ch);
    curl_close($ch);
    $result = json_decode($result);
    if ($result->code == 200) {
        $_SESSION['name'] = strtoupper($result->name);
        $_SESSION['API_key'] = $result->API_key;
        $_SESSION['preference'] = $result->preference;
        //echo $_SESSION['pref'];
        //die();
        setcookie("API_key", $result->API_key, time() + 3600);
        //die();
        header('Location: trending.php');
        exit();
    }
    else {
        $_SESSION['exists'] = false;
        header('Location: login.php');
        exit();
    }
    
?>