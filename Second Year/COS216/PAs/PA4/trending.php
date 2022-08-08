<!DOCTYPE html>

<html>
    <head>
        <title>DEV Games - PA1</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" href="./css/style.css"/>
        
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
        <script src="./script/script.js"></script>
    </head>


    <body class="background" onload="onTrendingload()">
    
        <?php 
            include "header.php";
            loadHeader(0);
            
            // echo '<style>';
            // echo 'html {filter: invert(100%);}';
            // echo 'img {filter: invert(100%);}';
            // echo '#trending {filter: invert(100%);}';
            // echo '#newReleases {filter: invert(100%);}';
            // echo '#topRated {filter: invert(100%);}';
            // echo '#featured {filter: invert(100%);}';
            // echo '#calender {filter: invert(100%);}';
            // echo '#dev {filter: invert(100%);}';
            // echo 'a {filter: invert(100%);}';
            // echo '</style>';
            
        ?>

        <div class="mainpage" id="trendingMain"></div>

        <?php
            include "footer.php";
            loadFooter();
        ?>
        
    </body>
</html>