<!-- 37. Store employee records (ID, Name, Department) and display details of employees in the “Sales” department. -->

<?php
$employee_arr = [
    ["ID" => 101, "Name" => "Ram", "Department" => "Sales"],
    ["ID" => 102, "Name" => "Sita", "Department" => "Production"],
    ["ID" => 103, "Name" => "Hari", "Department" => "Marketing"],
    ["ID" => 104, "Name" => "Shyam", "Department" => "Sales"],
];

echo "Details of employees in the sales department:<br>";
foreach ($employee_arr as $employees) {
    if ($employees["Department"] == "Sales")
        echo "ID: {$employees["ID"]}, Name: {$employees["Name"]}<br>";
}