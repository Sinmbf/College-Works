<!-- 18. Write a PHP script to demonstrate static properties sharing values across multiple objects. -->

<?php

class StaticClass
{
    static $balance = 2000;

    function depositAndShowBalance($depositAmount)
    {
        StaticClass::$balance += $depositAmount;
        echo "Current balance after deposit: " . (StaticClass::$balance);
    }
    function withdrawAndShowBalance($withdrawAmount)
    {
        StaticClass::$balance -= $withdrawAmount;
        echo "<br>Current balance after withdraw: " . (StaticClass::$balance);
    }
}

$s1 = new StaticClass();
$s2 = new StaticClass();
$s1->depositAndShowBalance(1000);
$s2->withdrawAndShowBalance(500);
?>