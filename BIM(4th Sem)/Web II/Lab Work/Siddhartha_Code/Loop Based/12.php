<!-- 12. Create a function that accepts a string and returns it in reverse order. -->

<?php

function reverseString($str)
{
    $revStr = "";
    for ($i = strlen($str) - 1; $i >= 0; $i--) {
        $revStr = $revStr . $str[$i];
    }
    return $revStr;
}

$str = "Sid";
echo "The reverse of '$str': " . reverseString($str);
?>
