<!-- 15. Write a function to count the number of words in a given sentence. -->

<?php
function countWords($str)
{

    $trimmed = trim($str); // remove leading and trailing white spaces
    $words = preg_split("/\s+/", $trimmed); // /.../ -> inside put regexp, \s -> any whitespace characters, '+' -> one or more of the previous element
    return ($words[0] == '') ? 0 : count($words); // If empty string return 0 otherwise return number of words
}

$str = "I am sid";
echo "Number of words in ' $str ': " . countWords($str);
?>
