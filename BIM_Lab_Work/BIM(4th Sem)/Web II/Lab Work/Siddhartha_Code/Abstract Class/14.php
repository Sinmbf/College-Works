<!--14. Create an abstract class `Shape` with an abstract method `area()` and implement it in `Triangle` and `Square`. -->

<?php
abstract class Shape
{
    abstract function area();
}

class Triangle extends Shape
{
    private $base;
    private $height;

    public function __construct($b, $h)
    {
        $this->base = $b;
        $this->height = $h;
    }

    function area()
    {
        echo "Area of triangle: " . (0.5 * $this->base * $this->height);
    }
}

class Square extends Shape
{
    private $side;

    public function __construct($l)
    {
        $this->side = $l;
    }

    function area()
    {
        echo "<br>Area of square: " . ($this->side * $this->side);
    }
}

// Usage
$t = new Triangle(3, 2);
$s = new Square(4);

$t->area(); // Area of triangle: 3
$s->area(); // Area of square: 16


?>