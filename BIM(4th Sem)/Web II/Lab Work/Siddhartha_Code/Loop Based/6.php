<!-- 6.	Write a PHP program to reverse a number using a loop. -->

<?php

$num = 1234;
$org_num = $num;
$rev = 0;
while ($num > 0) {
    $rem = $num % 10;
    $rev = $rev * 10 + $rem;
    $num = (int)($num / 10); // Use (int) to avoid float division; without it, num shrinks slowly and never hits 0, causing rev to grow endlessly and overflow to INF
}

echo "Reverse of $org_num: $rev";
?>
