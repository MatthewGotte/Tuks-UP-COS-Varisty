<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Dev Games</title>
    <link rel="stylesheet" href="./css/login.css"/>
    <script src="./script/signup.js"></script>
</head>

<body class="background">
    
    <div id="mainpage">

        <?php
            
            include "login_signup.php";

            $exists = false;
            if (!empty($_SESSION['exists'])) {
                if ($_SESSION['exists'] == true) {
                    $exists = true;
                }
                unset($_SESSION['exists']);
            }

            gen_page();
            loadSignUpForm($exists);

        ?>

    </div>

</body>

</html>