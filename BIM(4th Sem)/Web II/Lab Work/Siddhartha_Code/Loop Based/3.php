<!-- 3.	Write a script that uses a do...while loop to calculate the factorial of a number. -->

<?php
$num = 6;
$factorial = 1;
$i = 1;
do {
    $factorial *= $i;
    $i++;
} while ($i <= $num);
echo "Factorial of $num = $factorial";
?>