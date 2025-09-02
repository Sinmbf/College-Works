<!-- 27.Rotate a numeric array to the left by two positions. For example: [1, 2, 3, 4, 5] → [3, 4, 5, 1, 2]. -->

<?php
$arr = [1, 2, 3, 4, 5];
$n1 = $arr[0];
$n2 = $arr[1];
$length = count($arr);
for ($i = 0; $i < $length - 2; $i++) {
    $arr[$i] = $arr[$i + 2];
}
$arr[$i] = $n1;
$arr[$i + 1] = $n2;
echo "After rotation to the left by two position: ";
foreach ($arr as $num)
    echo $num . "&nbsp;&nbsp;";
?>