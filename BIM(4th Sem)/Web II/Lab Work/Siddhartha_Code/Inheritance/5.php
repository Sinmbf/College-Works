<!-- 5. Create a base class `Person` and a derived class `Student` that adds roll number and grade. -->

<?php
// Base class
class Person
{
    public $name;
    public $address;

    public function __construct($name, $address)
    {
        $this->name = $name;
        $this->address = $address;
    }

    public function showPerson()
    {
        echo "Name: $this->name<br>Address: $this->address";
    }
}

class Student extends Person
{
    public $roll;
    public $grade;

    public function __construct($name, $address, $grade, $roll)
    {
        parent::__construct($name, $address);
        $this->grade = $grade;
        $this->roll = $roll;
    }

    public function showStudent()
    {
        $this->showPerson();
        echo "<br>Roll: $this->roll<br>Grade: $this->grade";
    }
}

$s = new Student("Sinmbf", "Dallu", "A", 19);
echo "Student details:<br>";
$s->showStudent();
?>