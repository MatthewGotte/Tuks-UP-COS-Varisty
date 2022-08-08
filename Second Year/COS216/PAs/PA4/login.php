<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Dev Games</title>
    <link rel="stylesheet" href="./css/login.css"/>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>

    <script src="./script/login.js"></script>
</head>

<body class="background">
    
    <div id="mainpage">

        <?php
            include "login_signup.php";
        
            $exists = false;

            if (isset($_SESSION['exists'])) {
                if ($_SESSION['exists'] == false) {
                    $exists = true;
                }
                unset($_SESSION['exists']);
            }

            gen_page();
            loadLogInForm($exists);
        ?>

    </div>

</body>

</html>