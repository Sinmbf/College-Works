<!-- 40. Build a timetable array for a class. Each day has subjects scheduled. Print the timetable for Wednesday. -->

<?php
$timetable = [
    "Sunday" => [
        "Cost Accounting" => "11-12",
        "OS" => "12-1",
        "BDCN" => "1:30-2:30",
    ],
    "Monday" => [
        "DBMS" => "11-12",
        "BDCN" => "12-1",
        "Economics" => "1:30-2:30",
    ],
    "Tuesday" => [
        "Cost Accounting" => "11-12",
        "DBMS" => "12-1",
        "BDCN" => "1:30-2:30",
    ],
    "Wednesday" => [
        "DBMS" => "11-12",
        "OS" => "12-1",
        "Cost Accounting" => "1:30-2:30",
    ],
    "Thursday" => [
        "Cost Accounting" => "11-12",
        "DBMS" => "12-1",
        "BDCN" => "1:30-2:30",
    ],
    "Friday" => [
        "DBMS" => "11-12",
        "BDCN" => "12-1",
        "OS" => "1:30-2:30",
    ],
];
$day = "Wednesday";
echo "Timetable for $day:<br>";
foreach ($timetable[$day] as $sub_name => $time) {
    echo "Subject: $sub_name, Time: $time<br>";
}
?>