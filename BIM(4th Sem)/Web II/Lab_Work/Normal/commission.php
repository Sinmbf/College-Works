<?php   
    $books_sold=1000;
    $price=350;
    if($books_sold<=1000){
        $commission=($price*$books_sold)*(2/100);
    }
    else if($books_sold<=2000){
        $commission=($price*$books_sold)*(3/100);
    }
    else if($books_sold<=4000){
        $commission=($price*$books_sold)*(4/100);
    }
    else{
        $commission=($price*$books_sold)*(5/100);
    }
    echo "Commission earned: ".$commission;
 ?>   