<!-- 17. Create a class `MathOperations` with static methods for `add()`, `subtract()`, and `multiply()`. -->

<?php
class MathOperations
{
    static function add($n1, $n2)
    {
        echo "Addition: " . ($n1 + $n2);
    }

    static function subtract($n1, $n2)
    {
        echo "<br>Subtraction: " . ($n1 - $n2);
    }

    static function multiply($n1, $n2)
    {
        echo "<br>Product: " . ($n1 * $n2);
    }
}

MathOperations::add(10, 20);
MathOperations::subtract(30, 20);
MathOperations::multiply(50, 20);
?>