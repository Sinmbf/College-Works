<!-- 15. Write a function to count the number of words in a given sentence. -->

<?php
function countWords($str)
{

    $trimmed = trim($str); // remove leading and trailing white spaces
    $words = preg_split("/\s+/", $trimmed); // /.../ -> inside put regexp, \s -> any whitespace characters, '+' -> one or more of the previous element
    if ($words[0] == '')  // if the string is empty return 0
        return 0;
    return count($words);
}

$str = "I am sid";
echo "Number of words in ' $str ': " . countWords($str);
?>