<!-- 11. Write a PHP function to check whether a number is even or odd. -->

<?php
function checkEvenOdd($num)
{
    echo ($num % 2 == 0) ? "$num is even" : "$num is odd";
}

$num=52;
checkEvenOdd($num);
?>
