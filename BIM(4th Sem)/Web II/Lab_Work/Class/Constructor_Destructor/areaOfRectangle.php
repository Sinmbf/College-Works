<?php

    class Rectangle{
        public $length;
        public $breadth;

        function __construct($l,$b){
            $this->length=$l;
            $this->breadth=$b;
        }

        function findArea(){
            echo "The area of rectangle: ".($this->length*$this->breadth);
        }

        function __destruct(){
            echo "<br>Program ended";
        }
    }

    $rect=new Rectangle(5,10);
    $rect->findArea();
?>