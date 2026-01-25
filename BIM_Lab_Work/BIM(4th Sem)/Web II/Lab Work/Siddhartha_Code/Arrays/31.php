<!-- 31. Write a program to search a value in an associative array and display the corresponding key. -->

<?php
$arr = ["Sita" => "Ram", "Geeta" => "Hari", "Deepika" => "Amit"];
$value = "Amit";
$exists = false;
foreach ($arr as $wife => $husband) {
    if ($husband == $value) {
        echo "$husband's wife is $wife (key)<br>";
        $exists = true;
        break;
    }
}
if ((strcasecmp($value, "Raj") == 0) || !$exists) {
    echo "Doesn't exist";
}
?>