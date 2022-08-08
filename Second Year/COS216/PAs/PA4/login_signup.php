<?php

    include "header.php";

    function gen_page() {
        echo '<div id="left">';
        echo '<div id="lefttop">';
        echo '<img id="logo_icon" src="./img/icons/logo_transparent.svg" alt="logo_transparent.svg"/>';
        echo '</div>';
        echo '<div id="leftbottom">';
        echo '<div id="title">';
        echo '<h1 id="dev">DEV</h1>';
        echo '<h1>Games</h1>';
        echo '</div>';
        echo '</div>';
        echo '</div>';
    }

    function loadSignUpForm($exists) {
        echo '<div id="signup_form">';
        echo '<h2 id="header">SIGN UP</h2>';
        echo '<div id="inputs">';

        echo '<form action="validate-signup.php" name="signupform" method="POST">';
        echo '<input id="name" name="name" class="inputbox" type="text" placeholder="Name"/>';
        echo '<input id="surname" name="surname" class="inputbox" type="text" placeholder="Surname"/>';
        echo '<input id="email" name="email" class="inputbox" type="text" placeholder="Email"/>';
        echo '<input id="password1" name="password" class="inputbox" type="password" placeholder="Password"/>';
        echo '</form>';
        echo '<input id="password2" class="inputbox" type="password" placeholder="Re-type password"/>';
        if ($exists) {
            echo '<h2 id="already_exists">Looks like that email is already exists. Try log in.</h2>';
        }
        echo '<br />';
        echo '<button class="button" onclick="signup_click()">SIGN UP</button>';
        echo '<p id="haveaccount">Have an account? <a id="loginlink" href="./login.php">Log In</a></p>';
        echo '</div>';
        echo '</div>';
    }

    function loadLogInForm($exists) {
        echo '<div id="login_form">';
        echo '<br />';
        echo '<br />';
        echo '<br />';
        echo '<br />';
        echo '<h2 id="header">LOG IN</h2>';
        echo '<div id="inputs">';
        echo '<form action="validate-login.php" name="loginform" method="POST">';
        echo '<input id="email" class="inputbox" name="email" type="text" placeholder="Email"/>';
        echo '<input id="password" class="inputbox" name="password" type="password" placeholder="Password"/>';
        echo '</form>';
        if ($exists) {
            echo '<h2 id="already_exists">Incorrect email / password. Try Sign Up</h2>';
        }
        //echo '<h2 id="already_exists"></h2>';
        echo '<br />';
        echo '<br />';
        echo '<p id="forgot"><a id="forgot_pass" href="google.com">forgot password?</a></p>';
        echo '<br />';
        echo '<button class="button" onclick="login_click()">LOG IN</button>';
        echo '<p id="haveaccount">Not signed up? <a id="loginlink" href="./signup.php">Sign Up</a></p>';
        echo '</div>';
        echo '</div>';
    }

?>