<?php
abstract class A
{
    public $l;
    public $b;
    abstract function getData();
    abstract function calcArea();
}

class B extends A{
    public function getData(){
        $this->l=20;
        $this->b=10;
    }

    public function calcArea(){
        echo "Area of rectangle: ".($this->l*$this->b);
    }
}

$b=new B();
$b->getData();
$b->calcArea();
?>