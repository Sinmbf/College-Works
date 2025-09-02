<?php   
    $num=1234;
    $rev=0;
    $cnum=$num;
    while((int)$num!=0){
        $rem=$num%10;
        $rev=$rev*10+$rem;
        $num=(int)$num/10;
    }
    echo "Reverse of ".$cnum.": ".$rev;
?>