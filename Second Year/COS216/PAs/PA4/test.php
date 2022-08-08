<?php

$post = json_decode(file_get_contents('php://input'));

$type = $post->type;
switch ($type) {
    case 'info':
        echo 'this will return a game';
        if (!isset($post->key)) {
            echo 'the req does not have a key';
        }
        break;
    case 'login':
        echo 'this will log a person in';
        break;
}
