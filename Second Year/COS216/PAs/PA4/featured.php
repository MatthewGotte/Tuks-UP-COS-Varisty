<!DOCTYPE html>

<html>
    <head>
        <title>DEV Games - PA1</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" href="./css/style.css"/>
  
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
        <script src="./script/script.js"></script>
    </head>

    <body class="background" onload="onFeaturedload()">
        
        <?php 
            include "header.php";
            loadHeader(3);
        ?>

        <div id="featuredMainpage" class="mainpage"></div>

        <?php
            include "footer.php";
            loadFooter();
        ?>

    </body>
</html>