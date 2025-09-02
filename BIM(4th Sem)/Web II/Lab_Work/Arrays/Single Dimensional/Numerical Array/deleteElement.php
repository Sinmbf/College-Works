<?php
$numArr = [10, 20, 30, 40];
$pos =3;
$length = count($numArr);
if ($pos > $length || $pos<0) {
    echo "Position out of reach";
} else {
    for($i=$pos-1;$i<$length-1;$i++){
        $numArr[$i]=$numArr[$i+1];
    }
    $numArr[$length-1]=null;
    foreach ($numArr as $num) {
        echo $num;
        echo "<br>";
    }
}

?>
