<?php
    $numArr=[10,20,10,20,10];
    $size=count($numArr); //6
    $uniqueArr=[];
    $k=0;
    
    for($i=0;$i<$size;$i++){
        for($j=$i+1;$j<$size && $numArr[$i]!=-1;$j++){
            if($numArr[$i]==$numArr[$j]){
                $numArr[$j]=-1;
            }
        }
        if($numArr[$i]!=-1){
            $uniqueArr[$k]=$numArr[$i];
            $k++;
        }
    }

    for($i=0;$i<$size;$i++){
        if($i<count($uniqueArr)){
            $numArr[$i]=$uniqueArr[$i];
            continue;
        }
        $numArr[$i]=null;
    }

    foreach($numArr as $num)
        echo $num."<br>";
    
?>