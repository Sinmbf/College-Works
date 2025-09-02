<!-- 14.Create a function to check whether a string is a palindrome. -->

<?php
function checkPalindrome($str)
{
    $revStr = "";
    for ($i = strlen($str) - 1; $i >= 0; $i--) {
        $revStr .= $str[$i];
    }
    echo (strcasecmp($revStr, $str) == 0) ? "$str is palindrome" : "$str is not palindrome";
}

$str = "mom";
checkPalindrome($str);
?>