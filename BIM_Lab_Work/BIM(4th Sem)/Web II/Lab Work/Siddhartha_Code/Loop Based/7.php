<!-- 7.	Display the Fibonacci series up to n terms using a for loop. -->

<?php

$n1 = $n3 = 0;
$n2 = 1;
$n = 5;
echo "Fibonacci series upto $n terms:<br>";
for ($i = 0; $i < $n; $i++) {
    echo "$n3<br>";
    $n3 = $n1 + $n2;
    $n1 = $n2;
    $n2 = $n3;
}
?>