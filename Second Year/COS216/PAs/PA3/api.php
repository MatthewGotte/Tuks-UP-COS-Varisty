<?php

    if (strtoupper($_SERVER['REQUEST_METHOD']) === 'GET') {
        $con_error = array (
            'status' => 'unsuccessful',
            'timestamp' => time(),
            'details' => 'get request is not supported!'
        );
        print(json_encode($con_error));
        exit;
    }

    $post = json_decode(file_get_contents('php://input'));
    $newReturn = Array();
    if (isset($GLOBALS['post']->return)) {
        if (!is_array($GLOBALS['post']->return)) {
            if ($GLOBALS['post']->return !== '*') {
                $con_error = array (
                    'status' => 'unsuccessful',
                    'timestamp' => time(),
                    'details' => 'invalid return type!'
                );
                print(json_encode($con_error));
                die();
            }
        }
        if (!($GLOBALS['post']->return == '*')) {
            foreach($GLOBALS['post']->return as $obj) {
                if ($obj == 'title') {
                    array_push($newReturn, 'name');
                } 
                else if ($obj == 'score') {
                    array_push($newReturn, 'metacritic');
                }
                else if ($obj == 'description') {
                    array_push($newReturn, 'description_raw');
                }
                else if ($obj == 'developer') {
                    array_push($newReturn, 'developers');
                }
                else if ($obj == 'age_rating') {
                    array_push($newReturn, 'esrb_rating');
                }
                else array_push($newReturn, $obj);
            }
            $post->return = $newReturn;
        }
    }
    
    $rawdata = array();
    header('Content-type: application/json');
    DEFINE('BR', '<br />');
    $con_error = array (
        'status' => 'unsuccessful',
        'timestamp' => time(),
        'details' => 'unable to connect to external APIs'
    );

    class api
    {
        private static $_instance = null;
            private function  __construct() { 
                    $template = array(
                    'status' => 'unsuccessful',
                    'timestamp' => time()
                );
                include 'config.php';
                if (isset($GLOBALS['post']->key)) {
                    if (false) {
                        $code = array('error' => 'connection to MySQL failed / invalid key was provided');
                        $fail = array_merge($template, $code);
                        echo json_encode($fail);
                        die();
                    }
                }
                else {  
                    $code = array('error' => 'Key was not provided');
                        $fail = array_merge($template, $code);
                        echo json_encode($fail);
                    die();
                }    
                if (!isset($GLOBALS['post']->type)) {
                    $code = array('error' => 'type parameter is missing');
                    $fail = array_merge($template, $code);
                    echo json_encode($fail);
                    die();
                }
                if (!isset($GLOBALS['post']->return)) {
                    $code = array('error' => 'return parameter is missing');
                    $fail = array_merge($template, $code);
                    echo json_encode($fail);
                    die();
                }
                //servereq();
            } 
        private function  __clone() { }
        public static function getInstance()
        {
            if( !isset(self::$_instance) )
            self::$_instance = new api();
            return self::$_instance;
        }
        
    }

    $obj = api::getInstance();
    servereq();

    function checkKey($dbc, $inkey) {
        $query = 'SELECT * FROM users WHERE API_key="' . $inkey . '";';
        //echo BR . $query . BR;
        $response = @mysqli_query($dbc, $query);
        $row = mysqli_fetch_array($response);
        if ($row == null) return false;
        return true;
    }

    function servereq() {
        $type = $GLOBALS['post']->type;
        switch ($type) {
            case 'info':
                info();
                break;
            case 'update':
                update();
                break;
            case 'login':
                login();
                break;
            case 'rate':
                rate();
                break;
            case 'track':
                track();
                break;
        }
    }

    function p_search() {
        if (isset($GLOBALS['post']->title)) {
            return true;
        }
        return false;
    }

    function p_score() {
        if (isset($GLOBALS['post']->score)) {
            return true;
        }
        return false;
    }
    $filtered = [];

    function info() {
        //PA3
        $ftg = qFTG('https://www.freetogame.com/api/games');
        if (!isset($ftg)) {
            echo json_encode($GLOBALS['con_error']);
            die();
        }
        $urls=[];
        $counter = 0;
        foreach(json_decode($ftg) as $game) {
            array_push($urls, 'https://api.rawg.io/api/games/' . $game->title . '?&key=2d0ea18c88814df88a6f48b1cb2467f1&dates=2019-09-01,2019-09-30&platforms=18,1,7');
            if ($counter == 70) break;
            $counter++;
        }
        multiThreadQuery($urls);
        
        if (isset($GLOBALS['post']->title)) {
            if ($GLOBALS['post']->title != "*") {
                if (p_search() || p_score()) {

                    if(p_search()) {
                        //$GLOBALS['filtered'] = Array();
                        $search_1 = searchGames($GLOBALS['post']->title);
                        if ($search_1 != true) {
                            $add_game = getNewGame($GLOBALS['post']->title);
                            if ($add_game != true) { }
                            else {
                                $search_2 = searchGames($GLOBALS['post']->title);
                                if ($search_2 != true) {
                                    $template = array(
                                        'status' => 'unsuccessful',
                                        'timestamp' => time(),
                                        'error' => 'no content was found'
                                    );
                                    print(json_encode($template));
                                    die();
                                }
                            }
                        } 
                    }
        
                    if (p_score()) {
                        if (@$GLOBALS['filtered'] == null) {
                            filterMetacritic(@$GLOBALS['post']->score, true);
                        }
                        else {
                            filterMetacritic(@$GLOBALS['post']->score, false);
                        }
                    }
            
                    @output($GLOBALS['filtered']);
                    die();
                } 
            }
        }

            //output($GLOBALS['rawdata']);

        if (isset($GLOBALS['post']->title)) {
            if ($GLOBALS['post']->title == '*') {
                output($GLOBALS['rawdata']);
                die();
            }
        }
        $con_error = array (
            'status' => 'successful',
            'timestamp' => time(),
            'details' => 'no parameters or wild cards were given'
        );
        print(json_encode($con_error));

    }

    function filterMetacritic($score, $flag) {
        $new_array = Array();
        if ($flag) {
            foreach (json_decode($GLOBALS['rawdata']) as $game) {
                if (isset($game->metacritic))
                if ($game->metacritic >= $score) {
                    if (@$GLOBALS['filtered'] != null)
                    $temp [] = json_decode($GLOBALS['filtered']);
                    $temp [] = $game;
                    $GLOBALS['filtered'] = json_encode($temp);
                }
            }
        }
        else {
            $new_filtered = Array();
            foreach (json_decode($GLOBALS['filtered']) as $game) {
                if ($game->metacritic == null) continue;
                if ($game->metacritic >= $score) {
                    if ($new_filtered != null)
                    $temp [] = json_decode($GLOBALS['filtered']);
                    $temp [] = $game;
                    $new_filtered = json_encode($temp);
                }
            } 
            $GLOBALS['filtered'] = $new_filtered;
        }
    }

    function searchGames($name) {
        $name = strtolower($name);
        $temp = Array();
        $games = json_decode($GLOBALS['rawdata']);
        foreach ($games as $game) {
            $g_name = json_encode($game);
            $g_name = strtolower($g_name);
            if (strpos($g_name, $name) !== false) {
                if (@$GLOBALS['filtered'] != null)
                    $temp [] = json_decode($GLOBALS['filtered']);
                $temp [] = $game;
                $GLOBALS['filtered'] = json_encode($temp);
            }
        }
        if (@$GLOBALS['filtered'] == null) return false;
        return true;
    }

    function output($input) {
        $template = array(
            'status' => 'unsuccessful',
            'timestamp' => time(),
            'error' => 'no content was found'
        );
        $out_temp = array(
            'status' => 'successful',
            'timestamp' => time()
        );
        if ($input == null) {
            print(json_encode($template));
            die();
        }
        if ($GLOBALS['post']->return == '*') {
            $out_temp += ['data' => json_decode($input)];
            print(json_encode($out_temp));
        }
        else {
            //make a plan here:
            $return_arr = Array();
            foreach (json_decode($input) as $game) {
                if (!isset($game->name)) continue;
                $temp = Array();
                foreach ($GLOBALS['post']->return as $type) {
                    if (isset($game->$type)) {
                        $temp += [$type => $game->$type];
                    }
                    else $temp += [$type => 'invalid return parameter'];
                }
                //echo json_encode($temp);
                array_push($return_arr, $temp);
            }
            $out_temp += ['data' => $return_arr];
            print(json_encode($out_temp));
        }
    }

    function update() {
        //PA4
    }

    function login() {
        //PA4
    }

    function rate() {
        //PA4
    }

    function track() {
        //HW
    }

    function getNewGame($name) {
        $name = str_replace(' ', '-', $name);
        $game = qRAWG('https://api.rawg.io/api/games/' . $name . '?&key=2d0ea18c88814df88a6f48b1cb2467f1&dates=2019-09-01,2019-09-30&platforms=18,1,7');
        if (isset(json_decode($game)->detail)) {
            if (json_decode($game)->detail == 'Not found.') { 
                return false;
            }
        }
        appendGame($game);
        return true;
    }

    function appendGame($game) {
        if ($GLOBALS['rawdata'] != null)
            $temp [] = json_decode($GLOBALS['rawdata']);
        $temp [] = json_decode($game, true);
        $GLOBALS['rawdata'] = json_encode($temp);
    }

    //////////////////
    //REQUEST SITES://
    //////////////////
    function qRAWG($url) {
        $curl = curl_init();
        curl_setopt_array($curl, [
            CURLOPT_RETURNTRANSFER => 1,
            CURLOPT_URL => $url,
            CURLOPT_USERAGENT => 'Codular Sample cURL Request'
        ]);
        $resp = curl_exec($curl);
        curl_close($curl);
        return $resp;
    }

    function qFTG($url) {
        $curl = curl_init();
        curl_setopt_array($curl, [
            CURLOPT_RETURNTRANSFER => 1,
            CURLOPT_URL => $url,
            CURLOPT_USERAGENT => 'Codular Sample cURL Request'
        ]);
        $resp = curl_exec($curl);
        curl_close($curl);
        return $resp;
    }

    function multiThreadQuery($nodes) {
        $node_count = count($nodes);
        $curl_arr = array();
        $master = curl_multi_init();
        for($i = 0; $i < $node_count; $i++)
        {
            $url =$nodes[$i];
            $curl_arr[$i] = curl_init($url);
            curl_setopt($curl_arr[$i], CURLOPT_RETURNTRANSFER, true);
            curl_multi_add_handle($master, $curl_arr[$i]);
        }
        do {
            curl_multi_exec($master,$running);
        } while($running > 0);
        for($i = 0; $i < $node_count; $i++)
        {
            if ($curl_arr[$i] != null) {
                $results[] = curl_multi_getcontent  ( $curl_arr[$i]  );
            }
        }
        ///
        foreach($results as $res) {
            if (isset(json_decode($res)->detail)){
                if (json_decode($res)->detail)
                    continue;
            }
            $temp[] = json_decode($res, true);
        }
        $GLOBALS['rawdata'] = json_encode($temp);
    }

?>