<!-- Create a multidimensional array to store information about 3 students, each having a name, age and an array of
     marks of 3 subjects. Display the average marks of each student. -->

     <?php  
        $std_arr=[
            ["Name"=>"Ram","Age"=>20,["Sub1"=>95, "Sub2"=>80,"Sub3"=>75]],
            ["Name"=>"Shyam","Age"=>25,["Sub1"=>91, "Sub2"=>60,"Sub3"=>55]],
            ["Name"=>"Hari","Age"=>30,["Sub1"=>85, "Sub2"=>80,"Sub3"=>65]],
        ];

        foreach($std_arr as $students){
            echo $student["Name"];
        }
    ?>