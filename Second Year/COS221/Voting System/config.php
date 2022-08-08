<?php
        $name = "u20469366_elections";
        $password = "XBBOSF6IVKIPZNFLTUAJMIQHW2KDPXLV";
        $server = "wheatley.cs.up.ac.za";
        $username = "u20469366";

        $conn = mysqli_connect($server,$username,$password,$name) ;
        if(!$conn)
        {
            die("Failure to connect To Database:" . mysqli_connect($conn));
        }
?>