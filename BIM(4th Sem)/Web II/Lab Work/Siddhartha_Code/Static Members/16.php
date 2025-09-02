<!-- 16. . Write a PHP program to create a `Counter` class with a static property to count how many objects are created. -->

<?php

class Counter
{
    static $count = 0;
    public function __construct()
    {
        Counter::$count++;
    }
}

$c1 = new Counter();
$c2 = new Counter();
$c3 = new Counter();
echo "Number of objects created: " . Counter::$count;
?>