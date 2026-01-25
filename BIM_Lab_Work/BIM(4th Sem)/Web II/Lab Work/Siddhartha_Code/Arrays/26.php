<!-- 26. Accept five numbers from the user in a numeric array and display only the prime numbers. -->

<?php

$arr = [1, 2, 3, 4, 5];
$length = count($arr);
echo "Prime numbers in the array:<br>";
for ($i = 0; $i < $length; $i++) {
    $isPrime = true;
    for ($j = 2; $j < $arr[$i]; $j++) {
        if ($arr[$i] % $j == 0) {
            $isPrime = false; // If divisible by any number other than 1 and itself, 
            // then not prime.
            break;
        }
    }
    if ($isPrime)
        echo $arr[$i] . "<br>";
}
?>