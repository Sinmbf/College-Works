<!-- 13. Write a function that takes an array of numbers and returns the average. -->

<?php
function average($arr)
{
    $sum = 0;
    $size = count($arr);
    for ($i = 0; $i < $size; $i++) {
        $sum += $arr[$i];
    }
    return $sum / $size;
}

$arr = [1, 2, 3, 4, 5];
echo "The average of values in the array: " . average($arr);
?>