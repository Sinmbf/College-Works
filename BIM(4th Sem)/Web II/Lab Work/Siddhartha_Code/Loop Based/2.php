<!-- 2.	Create a program to print a multiplication table of a number using for loop. -->

<?php
$num = 5;
echo "Multiplication table of $num:<br>";
for ($i = 1; $i <= 10; $i++) {
    echo "$num * $i = " . ($num * $i) . "<br>";
}

?>
