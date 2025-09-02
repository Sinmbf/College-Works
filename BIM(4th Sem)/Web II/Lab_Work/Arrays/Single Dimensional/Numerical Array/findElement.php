<?php   
    $numArr=[1,2,4,6];
    $key=4;
    $length=count($numArr);
    $found=0;
    $index=0;
    foreach($numArr as $n){
        if($key==$n){
            echo "Element found at index: ".$index;
            $found=1;
            break;
        }
        $index++;
    }
    if($found==0){
        echo "Element not found";
    }
?>