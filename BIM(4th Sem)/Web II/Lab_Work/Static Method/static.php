<?php
    class A{
        static $n1;
        static $n2;
        
        static function sum(){
            echo "Sum of ".A::$n1." and ".A::$n2." = ".(A::$n1+A::$n2); 
        }
    }

    A::$n1=20;
    A::$n2=30;
    A::sum();
?>