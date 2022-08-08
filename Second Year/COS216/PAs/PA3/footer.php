<?php
    function loadFooter() {
        echo '<div class="footerback">';
        echo '<p class="footer">API Key = ' . $_SESSION['API_key'] . '</p>';
        echo '<p class="footer"><a style="color: #05acf4;" href="./api.php">Go to your api session<a></p>';
        echo '<p class="footer">2021</p>';
        echo '<p class="footer">by Matthew Gotte (u20734621).</p>';
        echo '</div>';
    }
?>