<?php
    $file=fopen("C:/xampp/htdocs/BIM4th_Siddhartha/write.txt","a");
    if($file){
        fwrite($file," Hello");
        echo "Successfully appended to file";
        fclose($file);
    }
    else{
        echo "Error while opening file";
    }
?>