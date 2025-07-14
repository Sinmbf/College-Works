<!-- 8.	Create a program that finds all prime numbers between 1 and 100 using a loop. -->

<?php
echo "Prime numbers between 1 and 100:<br>";
for ($i = 2; $i < 100; $i++) {
    $isPrime = 1;
    for ($j = 2; $j < $i; $j++) {
        if ($i % $j == 0) {
            $isPrime = 0; // not prime if divisible by any number other than 1 and itself
            break;
        }
    }
    if ($isPrime == 1)
        echo "$i&nbsp;&nbsp;&nbsp;"; // print if prime
}

?>