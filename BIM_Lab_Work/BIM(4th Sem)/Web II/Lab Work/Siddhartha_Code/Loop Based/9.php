<!-- 9.	Write a PHP script to find the largest number in an array using a foreach loop. -->

<?php
$arr = [2, 3, 4, 511, 3492, 5];
$largest = $arr[0];

foreach ($arr as $num) {
    if ($num > $largest)
        $largest = $num;
}

echo "The largest number in the array: $largest";
?>