<?php
    $flag=1;
    $num=4;
    for($i=2;$i<$num;$i++){
        if($num%$i==0){
            $flag=0;
            break;
        }
    }
    if($flag){
        echo $num." is a prime number";
    }
    else{
        echo $num." is not a prime number";
    }
?>