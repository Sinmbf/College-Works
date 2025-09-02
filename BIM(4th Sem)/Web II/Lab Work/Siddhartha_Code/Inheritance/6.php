<!-- 6. Write a PHP program to show method overriding using a `Vehicle` base class and a `Car` subclass. -->

<?php
// Parent Class
class Vehicle
{
    public function drive()
    {
        echo "Vehicle is being driven";
    }
}

// Child Class
class Car extends Vehicle
{
    public function drive()
    {
        echo "Car is being driven";
    }
}

// Create object
$c = new Car();
$c->drive();
?>