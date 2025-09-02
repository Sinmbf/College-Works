<?php
    // $ageArr=["Ram"=>20,"Shyam"=>30,"Hari"=>25];
    // $findPerson="Hari";
    // $found=0;
    // foreach($ageArr as $key=>$value){
    //     if($findPerson==$key){
    //         echo "$key : $value years old <br>";
    //         $found=1;
    //     }
    // }
    $ageArr=[
        ["Name"=>"Ram","Age"=>20],
        ["Name"=>"Shyam","Age"=>25],
        ["Name"=>"Hari","Age"=>30],
    ];
    $findPerson="Shyam";
    foreach($ageArr as $key=>$value){
        if($value["Name"]==$findPerson){
            echo $value["Name"]." : ".$value["Age"];
        }
    }
?>