<!-- WAP to generate prime number upto n using class -->

<?php
class Number
{

    function __construct(){}
    function generatePrime($n)
    {
        for ($i = 1; $i <= $n; $i++) {
            $isPrime = 1;
            for ($j = 2; $j < $i; $j++) {
                if ($i % $j == 0) {
                    $isPrime = 0;
                    break;
                }
            }
            if ($isPrime == 1) {
                echo $i . "<br>";
            }
        }
    }
}

$num = 15;
$n = new Number();
echo "Prime numbers upto $num:<br> ";
$n->generatePrime($num);

?>