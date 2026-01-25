<!-- 22. Create a PHP function that reverses a numeric array without using built-in functions like array_reverse(). -->

<?php
function reverseArray(&$arr)
{
    $right = count($arr) - 1;
    for ($i = 0; $i < count($arr) / 2; $i++) {
        $temp = $arr[$i];
        $arr[$i] = $arr[$right - $i];
        $arr[$right - $i] = $temp;
    }
}

$arr = [1, 2, 3, 4, 5];
reverseArray($arr);
echo "Reversed array:<br>";
foreach ($arr as $num) {
    echo $num . "<br>";
}
?>