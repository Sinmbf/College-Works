<!-- 34. Create a 2D array to store marks of 5 students in 3 subjects. Calculate total and average for each student. -->

<?php
$arr = [
    "Ram" => [34, 54, 33],
    "Shyam" => [64, 80, 70],
    "Gopal" => [98, 82, 55],
    "Hari" => [88, 82, 65],
    "Sita" => [78, 80, 66],
];

foreach ($arr as $students => $marks) {

    $total = 0;
    $average = 0;
    foreach ($marks as $mark) {
        $total += $mark;
        $average = $total / 3;
    }
    echo "<b>For $students:</b><br>Total marks: $total<br>Average: " . round($average, 2) . "<br>";
}

?>