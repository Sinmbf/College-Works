<!-- WAP to calculate area of circle using class -->

<?php
class Circle
{
    public $r;

    function getData($r)
    {
        $this->r = $r;
    }

    function calcArea()
    {
        echo "The area of circle: " . ((22 / 7) * $this->r * $this->r);
    }
}

$c = new Circle();
$c->getData(2);
$c->calcArea();
?>