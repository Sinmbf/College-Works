<?php
    $arr=["Fan"=>2000,"Mobile"=>20000,"Fridge"=>7000,"Battery"=>500];
    $price=5000;
    foreach($arr as $key=>$value){
        if($value>5000){
            echo "$key : $value<br>";
        }
    }

?>