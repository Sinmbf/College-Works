<!-- 21. Write a PHP script to find the second largest number in a numeric array. -->

<?php
$arr = [1, 2, 343, 55, 212, 2];
$largest = $second_largest = $arr[0];
foreach ($arr as $num) {
    if ($num > $largest) {
        $second_largest = $largest;
        $largest = $num;
    }
    if ($num > $second_largest && $num != $largest) {
        $second_largest = $num;
    }
}

echo "The second largest element in the array: $second_largest";
?>