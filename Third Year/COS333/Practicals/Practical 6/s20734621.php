<?php

    //u20734621 - Matthew Gotte
    //run:
    //php s20734621.php

    $input = $argv[1];

    $converted = convertInput($input);

    echo "<!DOCTYPE html>\n";
    echo "<html lang='en'>\n";
    echo "<head>\n";
    echo "<meta charset='UTF-8'>\n";
    echo "<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n";
    echo "<title>u20734621 - Prac 6</title>\n";
    echo "</head>\n";
    echo "<body>\n";
    if (isPalindrome($converted))
        echo "<h1>Palindrome</h1>\n";
    else
        echo "<h1>Not a Palindrome</h1>\n";
    echo "</body>\n";
    echo "</html>\n";

    // convertInput
    function convertInput($input) {
        $output = strtolower($input);
        $output = preg_replace( '/[\W]/', '', $output);
        return $output;
    }

    function isPalindrome($input) {
        return $input == strrev($input);
    }

?>