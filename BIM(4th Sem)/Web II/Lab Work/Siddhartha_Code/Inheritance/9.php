<!-- 9. Make a class `Shape` and create subclasses `Circle` and `Rectangle` to calculate area (runtime polymorphism). -->

<?php

class Shape
{
    public function calcArea()
    {
        echo "Calculate area of shape";
    }
}

class Circle extends Shape
{
    public $radius;

    public function __construct($radius)
    {
        $this->radius = $radius;
    }

    public function calcArea()
    {
        echo "Area of circle: " . round(((22 / 7) * $this->radius * $this->radius), 2) . "<br>";
    }
}

class Rectangle extends Shape
{
    public $length;
    public $breadth;

    public function __construct($length, $breadth)
    {
        $this->length = $length;
        $this->breadth = $breadth;
    }

    public function calcArea()
    {
        echo "Area of rectangle: " . ($this->length * $this->breadth);
    }
}

$c = new Circle(4);
$r = new Rectangle(5, 6);
$c->calcArea();
$r->calcArea();
?>