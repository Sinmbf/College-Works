<?php
    $arr1=["Name"=>"Ram","Age"=>20];
    $arr2=["Hobby"=>"Basketball","Class"=>12];
    $arr3=$arr1+$arr2;

    foreach($arr3 as $key=>$value){
        echo "$key: $value<br>";
    }