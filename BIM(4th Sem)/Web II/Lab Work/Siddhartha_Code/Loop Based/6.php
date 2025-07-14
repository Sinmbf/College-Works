<!-- 6.	Write a PHP program to reverse a number using a loop. -->

<?php

$num = 1234;
$org_num = $num;
$rev = 0;
while ($num > 0) {
    $rem = $num % 10;
    $rev = $rev * 10 + $rem;
    $num = (int)($num / 10); // Convert to int because '/' performs floating point division in php. So it keeps on changing num to a very small floating point number. This prevents the num from reaching 0. Eventually, rev becomes very large due to accumulating digits from incorrect remainders — finally, it overflows and becomes INF
}

echo "Reverse of $org_num: $rev";
?>