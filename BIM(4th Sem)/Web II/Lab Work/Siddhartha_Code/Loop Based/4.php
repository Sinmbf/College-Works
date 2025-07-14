<!-- 4.	Use a loop to calculate the sum of digits of a given number in PHP. -->

<?php
$num = 12345;
$onum = $num;
$sum = 0;

while ($num > 0) {
    $rem = $num % 10;
    $sum += $rem;
    $num /= 10;
}
echo "The sum of digits of $onum = $sum";
?>