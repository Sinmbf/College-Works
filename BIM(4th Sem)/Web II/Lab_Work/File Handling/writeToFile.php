<?php

    $file=fopen("C:/xampp/htdocs/BIM4th_Siddhartha/write.txt","w");
    if($file){
        fwrite($file,"I am sid");
        echo "Successfully written to file";
        fclose($file);
    }
    else{
        echo "Error while opening file";
    }

?>