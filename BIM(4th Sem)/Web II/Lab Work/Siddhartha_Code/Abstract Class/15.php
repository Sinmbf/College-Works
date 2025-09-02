<!-- 15. Make an abstract class `Employee` with an abstract method `calculateSalary()` and extend it for `FullTimeEmployee` and `PartTimeEmployee`. -->

<?php
abstract class Employee
{
    abstract function calculateSalary();
}

class FullTimeEmployee extends Employee
{
    private $monthlySalary;
    public function __construct($monthlySalary)
    {
        $this->monthlySalary = $monthlySalary;
    }
    function calculateSalary()
    {
        return $this->monthlySalary;
    }
}

class PartTimeEmployee extends Employee
{
    function calculateSalary($hourlyRate = 0, $hoursWorked = 0)
    {
        return $hourlyRate * $hoursWorked;
    }
}

$fte = new FullTimeEmployee(20000);
$pte = new PartTimeEmployee();
$fullTimeSalary = $fte->calculateSalary();
$partTimeSalary = $pte->calculateSalary(200, 40);
echo ("Full time salary: $fullTimeSalary<br>Part time salary: $partTimeSalary");
?>