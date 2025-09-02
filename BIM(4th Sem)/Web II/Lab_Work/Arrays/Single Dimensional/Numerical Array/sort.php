<?php   
    $numArr=[10,20,30,40];
    $key=40;
    $length=count($numArr);
    for($i=0;$i<$length-1;$i++){
        for($j=$i+1;$j<$length;$j++){
            if($numArr[$i]>$numArr[$j]){
                $temp=$numArr[$j];
                $numArr[$j]=$numArr[$i];
                $numArr[$i]=$temp;
            }
        }
    }
    foreach($numArr as $num){
        echo $num."<br>";
    }