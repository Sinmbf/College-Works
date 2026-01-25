<!-- 17. Write a recursive function to calculate the factorial of a number. -->

<?php
function factorial($num)
{
    if ($num == 0)
        return 1;
    return $num * factorial($num - 1);
}

$num = 6;
echo "Factorial of $num: " . factorial($num);
?>