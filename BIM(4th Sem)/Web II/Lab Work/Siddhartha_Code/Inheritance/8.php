<!-- 8. Write a PHP program to demonstrate the use of parent constructor using `parent::__construct()` in inheritance. -->

<?php
class Base
{
    public function __construct()
    {
        echo "Parent constructor<br>";
    }
}

class Child extends Base
{
    public function __construct()
    {
        parent::__construct();
        echo "Child constructor";
    }
}

$c = new Child();
?>