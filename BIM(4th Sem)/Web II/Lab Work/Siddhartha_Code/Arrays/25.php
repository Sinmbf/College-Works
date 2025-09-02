<!-- 25. Write a PHP program that sorts an array in descending order manually (without rsort()). -->

<?php

$arr = [0, 1, 2, 3, 4, 5];
for ($i = 0; $i < count($arr) - 1; $i++) {
    for ($j = $i + 1; $j < count($arr); $j++) {
        if ($arr[$i] < $arr[$j]) {
            $temp = $arr[$i];
            $arr[$i] = $arr[$j];
            $arr[$j] = $temp;
        }
    }
}

echo "Array in descending order:<br> ";
foreach ($arr as $num)
    echo "$num<br>";
?>