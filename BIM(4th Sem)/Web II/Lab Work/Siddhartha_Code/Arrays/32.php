<!-- 32. Store employee names as keys and departments as values. Count how many employees are in each department. -->

<?php
$emp_arr = ["Ram" => "Production", "Sita" => "Marketing", "Hari" => "Accounting", "Geeta" => "Production", "Gopal" => "Marketing", "Deepa" => "Marketing"];
$departmentCount = [];

foreach ($emp_arr as $emp => $department) {
    $isPresent = false;
    // if (isset($departmentCount[$dep])) {  // isset() checks if the key already exists in the $departmentCounts array
    //     $departmentCount[$dep]++;
    // } else {
    //     $departmentCount[$dep] = 1;
    // }


    foreach ($departmentCount as $dep => $count) {
        if ($department == $dep) {
            $isPresent = true;
            break;
        }
    }
    if ($isPresent) {
        $departmentCount[$department]++;
    } else {
        $departmentCount[$department] = 1;
    }
}

foreach ($departmentCount as $dep => $count) {
    echo "Employees in $dep department: $count<br>";
}



?>