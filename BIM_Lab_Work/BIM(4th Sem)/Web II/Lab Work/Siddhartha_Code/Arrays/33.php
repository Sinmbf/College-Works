<!-- 33. Store user names and ages. Display users who are above 18 years. -->

<?php
$arr = [
    ["Name" => "Ram", "Age" => 18],
    ["Name" => "Shyam", "Age" => 20],
    ["Name" => "Hari", "Age" => 14],
    ["Name" => "Gopal", "Age" => 23],
];

echo "Users who are above 18 years:<br>";
foreach ($arr as $user) {
    if ($user["Age"] > 18)
        echo $user["Name"] . " => " . $user["Age"] . "<br>";
}
?>