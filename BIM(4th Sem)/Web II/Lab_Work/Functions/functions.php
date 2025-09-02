<?php
    // Function with argument and no return type
    function findSum1($num1,$num2){
        echo "$num1 + $num2 = ".($num1+$num2);
    }
    
    // Function with no argument and return type
    function findSum2(){
        $num1=10;
        $num2=15;
        echo "<br>$num1 + $num2 = ".($num1+$num2);
    }

    // Function with argument and return type
    function findSum3($num1,$num2){
        return $num1+$num2;
    }

    function findLargest($num1,$num2){
        return ($num1>$num2)?$num1:$num2;
    }

    // Function to find reverse of a number
    function getReverse($num){
        $rev=0;
        $cnum=$num;
        while((int)$num!=0){
            $rem=$num%10;
            $rev=$rev*10+$rem;
            $num=(int)$num/10;
        }
        echo "<br>Reverse of ".$cnum.": ".$rev;
    }

    // Function call
    findSum1(2,3);
    findSum2();
    echo "<br>Sum = ".findSum3(3,4);
    echo "<br>Largest is ".findLargest(10000,1000);
    getReverse(153);
?>