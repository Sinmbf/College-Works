<!-- 23. Write a program to calculate the average of elements in a numeric array. -->

<?php
$arr = [1, 2, 3, 4, 5];
$size = count($arr);
$sum = 0;
foreach ($arr as $num) {
    $sum += $num;
}
echo "Average of elements in the array: " . ($sum / $size);

?>