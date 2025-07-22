<!-- 36. Construct a multidimensional array to represent a monthly calendar. Display all dates of Sundays in the month. -->

<?php

// Of Baisakh 2081
$monthly_calendar = [
    "Sunday" => [2, 9, 16, 23, 30],
    "Monday" => [3, 10, 17, 24, 31],
    "Tuesday" => [4, 11, 18, 25],
    "Wednesday" => [5, 12, 19, 26],
    "Thursday" => [6, 13, 20, 27],
    "Friday" => [7, 14, 21, 28],
    "Saturday" => [1, 8, 15, 22, 29],
];
$day = "Sunday";

echo "All dates of $day in the month of Baisakh 2081:<br>";
foreach ($monthly_calendar[$day] as $date) {
    echo "$date&nbsp;&nbsp;&nbsp;";
}
?>