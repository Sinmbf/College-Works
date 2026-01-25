<!-- 20. Create a function that returns the nth term of the Fibonacci sequence using recursion. -->

<?php
function fibonacci($n)
{
    if ($n <= 1)
        return $n;
    $n2 = fibonacci($n - 1) + fibonacci($n - 2);
    return $n2;
}

$n = 5;
for ($i = 0; $i < $n; $i++) {
    echo fibonacci($i) . "<br>";
}
?>