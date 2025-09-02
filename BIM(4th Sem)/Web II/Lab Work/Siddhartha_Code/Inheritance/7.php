<!-- 7. Create a class `Employee` with salary property and extend it into a `Manager` class that calculates bonus. -->

<?php
class Employee
{
    public $salary;

    public function  __construct($salary)
    {
        $this->salary = $salary;
    }
}

class Manager extends Employee
{
    public $bonus;

    public function __construct($salary, $bonus)
    {
        parent::__construct($salary);
        $this->bonus = $bonus;
    }

    public function calculateBonus()
    {
        echo "Bonus for $this->salary salary is: Rs " . (($this->bonus / 100) * $this->salary);
    }
}

$m = new Manager(30000, 10);
$m->calculateBonus();
?>