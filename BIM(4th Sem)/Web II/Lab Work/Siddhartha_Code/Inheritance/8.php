<!-- 8. Write a PHP program to demonstrate the use of parent constructor using `parent::__construct()` in inheritance. -->

<?php
class Person
{
    public $name;

    public function __construct($name)
    {
        $this->name = $name;
        echo "Person details set<br>";
    }
}

class Student extends Person
{
    public $grade;
    public function __construct($name, $grade)
    {
        parent::__construct($name);
        $this->grade = $grade;
        echo "Student details set";
    }
}

$c = new Student("Sinmbf", "A");
?>