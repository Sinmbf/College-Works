<?php

try{
    $a=10;
    $b=0;
    echo ($a/$b);

}
catch(DivisionByZeroError $e){
    echo $e->getMessage();
}