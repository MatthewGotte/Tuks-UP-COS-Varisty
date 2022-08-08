<?php
    
    DEFINE ('DB_USER', 'u20734621');
    DEFINE ('DB_PASSWORD', 'CKIWUUONAM65IUFTW6CHPP5KU6B3UKEK');
    DEFINE ('DB_HOST', 'wheatley.cs.up.ac.za');
    DEFINE ('DB_NAME', 'u20734621_dev_games');
    $dbc = @mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME)
    OR die('Connection to MySQL failed!' . mysqli_connect_error());

    /*
    DEFINE ('DB_USER', 'epiz_28693095');
    DEFINE ('DB_PASSWORD', '4BPPUmxXNMiw');
    DEFINE ('DB_HOST', 'sql311.epizy.com');
    DEFINE ('DB_NAME', 'epiz_28693095_dev_games');
    */

?>