<?php
$numArr = [1, 2, 3, 1, 2, 1, 3];
$length = count($numArr);
for ($i = 0; $i < $length; $i++) {
    $count=1;
    for($j=$i+1;$j<$length && $numArr[$i]!=-1;$j++){
       if($numArr[$i]==$numArr[$j]){
        $count+=1;
        $numArr[$j]=-1;
       }    
    }
    if($numArr[$i]!=-1)
        echo "The occurrence of ".$numArr[$i].": $count<br>";
}
// foreach($uniqueArr as $num){
//     echo $num;
// }

