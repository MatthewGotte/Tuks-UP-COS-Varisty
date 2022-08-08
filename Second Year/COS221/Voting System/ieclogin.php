<!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js"></script>
        <link rel="stylesheet" href="css/login_signup.css">
        <script src="./js/validatelogin.js"></script>
        <title>Login</title>
    </head>
    <body>
        <div id="mainpage">
            <?php
                include 'construct_login_signup.php';
                gen_page();
                loadiecloginform(false);
            ?>
        </div>
    </body>
</html>