<!-- 28. Write a PHP script that stores student names as keys and their scores as values. Find the student with the highest score. -->

<?php
$arr = ["Ram" => 90, "Sita" => 80, "Hari" => 95];
$highestMarks = 0;
$highestScorer;
foreach ($arr as $std_name => $marks) {
    if ($marks > $highestMarks) {
        $highestMarks = $marks;
        $highestScorer = $std_name;
    }
}

echo "Student with the highest score: $highestScorer with score: $highestMarks";
?>