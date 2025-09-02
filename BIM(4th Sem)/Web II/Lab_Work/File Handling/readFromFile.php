<?php
    $file=fopen("C:/xampp/htdocs/BIM4th_Siddhartha/write.txt","r");
    if($file){
        while(!feof($file)){
            echo fgets($file)."<br>";
        }
    }
    else{
        echo "Error opening the file";
    }
?>