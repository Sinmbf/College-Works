<!-- 19.Write a function that calculates the sum of an array using foreach. -->

<?php
function calcSumOfArray($arr)
{
    $sum = 0;
    foreach ($arr as $num) {
        $sum += $num;
    }
    echo "Sum of all elements of array: " . $sum;
}

$arr = [1, 2, 3, 4, 5];
calcSumOfArray($arr);
?>