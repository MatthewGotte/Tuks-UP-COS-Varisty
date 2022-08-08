<?php
    require_once('./config.php');
    session_start();
    function loadHeader($page) {
        $filter = "";
        $pagename = "";
        $searchfunction = "";
        $icon = "";
        $id_trending = "";
        $id_newreleases = "";
        $id_toprated = "";
        $id_featured = "";
        $id_calender = "";
        switch ($page) {
            case 0:
                $filter = "filterTrending";
                $pagename = "Trending";
                $id_trending = 'id="trending"';
                $searchfunction = "searchTrending()";
                $icon = "trending";
                break;
            case 1:
                $filter = "filterNewReleases";
                $pagename = "New Releases";
                $id_newreleases = 'id="newReleases"';
                $searchfunction = "searchNewReleases()";
                $icon = "newreleases";
                break;
            case 2:
                $filter = "filterTopRated";
                $pagename = "Top Rated";
                $id_toprated = 'id="topRated"';
                $searchfunction = "searchTopRated()";
                $icon = "toprated";
                break;
            case 3:
                $filter = "filterFeatured";
                $pagename = "Featured";
                $id_featured = 'id="featured"';
                $searchfunction = "searchFeatured()";
                $icon = "featured";
                break;
        }
        logos();
        echo '<div class="searchbox">';
        echo '<input id="textsearch" type="text" placeholder="Search for a game...">';
        echo '</div>';
        echo '<div class="linear">';
        echo '<div class="filter">';
        echo '<select id="' . $filter . '">';
        echo '<option value="" disabled selected hidden>' . $_SESSION['preference'] . '</option>';
        echo '<option value="">None</option>';
        echo '<option value="action">Action</option>';
        echo '<option value="arcade">Arcade</option>';
        echo '<option value="narrative">Narrative</option>';
        echo '<option value="strategy">Strategy</option>';
        echo '<option value="MMORPG">MMORPG</option>';
        echo '</select>';
        echo '</div>';
        echo '<button id="search" class="searchbutton" onclick="' . $searchfunction . '">Search</button>';
        echo '</div>';
        echo '</div>';
        echo '</div>';
        echo '<div class="pagetype">';
        echo '<img class = "slowLoad" src="img/icons/' . $icon . '_blue.svg" alt="' . $icon . '_blue.scg">';
        echo '<h1 class="slowLoad" id="pageheader">' . $pagename . '</h1>';
        echo '</div>';
        echo '<div class="panel2">';
        echo '<nav class="navbar">';
        echo '<a ' . $id_trending . ' class="navbar-item" href="./trending.php">TRENDING</a>';
        echo '<a ' . $id_newreleases . ' class="navbar-item" href="./newReleases.php">NEW RELEASES</a>';
        echo '<a ' . $id_toprated . ' class="navbar-item" href="./topRated.php">TOP RATED</a>';
        echo '<a ' . $id_featured . ' class="navbar-item" href="./featured.php">FEATURED</a>';
        echo '<a ' . $id_calender . ' class="navbar-item" href="./calender.php">CALENDER</a>';
        if (isset($_SESSION['name'])) {
            echo '<a class="navbar-item">USER: ' . $_SESSION['name'] . '</a>';
            echo '<a class="navbar-item" id="set_genre" onclick="tester()">SET GENRE</a>';
            echo '<a class="navbar-item" href="./logout.php">LOG OUT</a>';
        }
        else {
            echo '<a class="navbar-item" href="./login.php">LOG IN</a>';
        }
        echo '</nav>';
        echo '<h1 id="notfound" style="display: none;">Not found<h1>';
        echo '</div>';
    }

    function loadCalender() {
        logos();
        echo '<div id="showing" class="linear">';
        echo '<h1 id="month"></h1>';
        echo '<h1 id="year" class="blue"></h1>';
        echo '</div>';
        echo '</div>';
        echo '</div>';
        echo '<div class="panel2">';
        echo '<nav class="navbar">';
        echo '<a class="navbar-item" href="./trending.php">TRENDING</a>';
        echo '<a class="navbar-item" href="./newReleases.php">NEW RELEASES</a>';
        echo '<a class="navbar-item" href="./topRated.php">TOP RATED</a>';
        echo '<a class="navbar-item" href="./featured.php">FEATURED</a>';
        echo '<a id="calender" class="navbar-item" href="./calender.php">CALENDER</a>';
        if (isset($_SESSION['name'])) {
            echo '<a class="navbar-item">' . $_SESSION['name'] . '</a>';
            echo '<a class="navbar-item" href="./logout.php">LOG OUT</a>';
        }
        else {
            echo '<a class="navbar-item" href="./login.php">LOG IN</a>';
        }
        echo '</nav>';
        echo '<h1 id="notfound" style="display: none;">Not found</h1>';
        echo '</div>';
        echo '<div class="navbuttons">';
        echo '<button id="prev" onclick="prevMonth()">Previous Month</button>';
        echo '<button id="next" onclick="nextMonth()">Next Month</button>';
        echo '<button id="today" onclick="showtoday()">Show Today</button>';
        echo '<button onclick="refreshPage()">Calender</button>';
        echo '</div>';
    }

    function logos() {
        echo '<img class="absCenter" id="loading" src="./img/GIF/Spinner-1s-200px.gif" alt="loading_spinner.gif">';
        echo '<div class="panel1">';
        echo '<div class="linear">';
        echo '<div class="logo">';
        echo '<img src="./img/icons/logo_transparent.svg" alt="logo_transparent.svg"/>';
        echo '</div>';
        echo '<div class="vl"></div>';
        echo '<div class="linear">';
        echo '<h1 id="dev">DEV</h1>';
        echo '<h1>Games</h1>';
        echo '</div>';
    }

?>