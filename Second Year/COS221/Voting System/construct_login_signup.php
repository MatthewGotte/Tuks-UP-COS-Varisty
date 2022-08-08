<?php

    function gen_page() {
        echo '<div id="left">';
        echo '<div id="lefttop">';
        echo '</div>';
        echo '<div id="leftbottom">';
        echo '<div id="title">';
        echo '</div>';
        echo '</div>';
        echo '</div>';
    }

    function loadSignUpForm($exists) {
        echo '<div id="signup_form">';
        echo '<h2 id="header">REGISTER</h2>';
        echo '<div id="inputs">';

        echo '<form name="signupform" onsubmit="return sign_click()" action ="validate_signup.php"  method="POST">';
            //sign up inputs:
            echo '<input id="name" name="fname" class="inputbox" type="text" placeholder="Name"/>';
            echo '<p id="nerror"></p>';
            echo '<input id="surname" name="surname" class="inputbox" type="text" placeholder="Surname"/>';
            echo '<p id="serror"></p>';
            echo '<input id="initials" name="initials" class="inputbox" type="text" placeholder="Initials"/>';
            echo '<p id="muerror"></p>';
            echo '<input id="id" name="id" class="inputbox" type="" placeholder="SA ID Number"/>';
            echo '<p id="ierror"></p>';
            echo '<input id="email" name="email" class="inputbox" type="email" placeholder="Email"/>';
            echo '<p id ="eerror"></p>';
            echo '<input id="contact" name="contact" class="inputbox" type="" placeholder="+27 ..."/>';
            echo '<p id = "cerror"></p>';
            echo '<input id="address" name="address" class="inputbox" type="" placeholder="Address"/>';
            echo '<p  id = "addrerror"></p>';
            echo '<select id="areacode" name="areacode" class="inputbox" type="" placeholder="Area Code">';
            require_once "config.php";
            $sql = "SELECT * FROM metro";
                $result = mysqli_query($conn, $sql);
                while($row = mysqli_fetch_assoc($result)) {
                    ?>
                    <tr>
                                <option><?php echo $row['area_code'] ?></option>
                        </tr>
                    <?php
                }

            $sql = "SELECT * FROM local";
            $result = mysqli_query($conn, $sql);
            while($row = mysqli_fetch_assoc($result)) {
                ?>
                <tr>
                            <option><?php echo $row['area_code'] ?></option>
                    </tr>
                <?php
            }
            echo '</select>';
            echo '<p id = "arerror"></p>';
            echo '<select id="ethnicity" name="ethnicity" class="inputbox">';
            echo '<option>African</option>';
            echo '<option>Coloured</option>';
            echo '<option>White</option>';
            echo '<option>Indian/Asian</option>';
            echo '</select>';
            echo '<select id="sex" name="sex" class="inputbox">';
            echo '<option>M</option>';
            echo '<option>F</option>';
            echo '</select>';
            echo '<input id="password1" name="password1" class="inputbox" type="password" placeholder="Password"/>';
            echo '<p id = "p1error"></p>';
            echo '<input id="password2" name="password2" class="inputbox" type="password" placeholder="Re-enter password"/>';
            echo '<p id = "p2error"></p>';


        
        @session_start();
        if (@$_SESSION['exists'] === false) {
            echo '<h2 id="already_exists">Looks like that account already exists. Try log in.</h2>';
        }

        if (isset($_GET['error'])) {
            if ($_GET['error'] == 'exists') {
                echo '<p>You are alrady registered. Please Log In.</p>';
            }
            else if ($_GET['error'] == 'server_error') {
                echo '<p>Internal error occoured, please try again.</p>';
            }
        }

        echo '<input type ="submit" value="SIGN UP" name="submit" class="button" >';
        echo '<p id="haveaccount">Already registered? <a id="loginlink" href="./login.php">Log In</a></p>';
        echo '</div>';
        echo '</div>';
        
        echo '</form>';
    }

    function loadLogInForm($exists) {

        echo '<div id="login_form">';
        echo '<br />';
        echo '<br />';
        echo '<br />';
        echo '<h2 id="header">LOG IN</h2>';
        echo '<div id="inputs">';

        echo '<form name="loginform" action ="validate_login.php" onsubmit ="return sign_click()" method="POST">';
            //log in inputs:
            echo '<input id="id" class="inputbox" name="id" type="text" placeholder="SA ID Number"/>';
            echo '<p id = "ierror"></p>';
            echo '<input id="password" class="inputbox" name="password" type="password" placeholder="Password"/>';
            echo '<p id = "perror"></p>';
        
        echo '<br />';

        if (isset($_GET['error'])) {
            if ($_GET['error'] == 'failed') {
                echo '<p>Invalid ID/Password provided.</p>';
            }
        }

        echo '<input type="submit" name ="submit" value="LOGIN" class="button" >';
        echo '<p id="haveaccount">Not signed up? <a id="loginlink" href="./signup.php">Sign Up</a></p>';
        echo '<p id="haveaccount">IEC Worker? <a id="loginlink" href="./ieclogin.php">IEC Login</a></p>';
        echo '</div>';
        echo '</div>';
        echo '</form>';
    }

    function loadiecloginform($exists) {

        echo '<div id="login_form">';
        echo '<br />';
        echo '<br />';
        echo '<br />';
        echo '<h2 id="header">IEC LOG IN</h2>';
        echo '<div id="inputs">';

        echo '<form name="iecloginform" action ="validate_ieclogin.php" method="POST">';
            //log in inputs:
            echo '<input id="id" class="inputbox" name="iecid" type="text" placeholder="SA ID Number"/>';
            echo '<p id = "iecierror"></p>';
            echo '<input id="password" class="inputbox" name="iecpassword" type="password" placeholder="Password"/>';
            echo '<p id = "iecperror"></p>';
        
        echo '<br />';

        if (isset($_GET['error'])) {
            if ($_GET['error'] == 'failed') {
                echo '<p>Invalid ID/Password provided.</p>';
            }
        }

        echo '<input type="submit" name ="iecsubmit" value="LOGIN" class="button" >';
        echo '<p id="haveaccount">Standard Voter? <a id="loginlink" href="./login.php">Login</a></p>';

        echo '</div>';
        echo '</div>';
        echo '</form>';
    }

?>