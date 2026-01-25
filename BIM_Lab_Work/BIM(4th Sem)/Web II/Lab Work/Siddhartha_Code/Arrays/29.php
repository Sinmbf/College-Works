<?php
$arr = [
    ["Country" => "Nepal", "Capital" => "Kathmandu"],
    ["Country" => "India", "Capital" => "New Delhi"],
    ["Country" => "United States", "Capital" => "Washington DC"],
    ["Country" => "France", "Capital" => "Paris"],
    ["Country" => "Japan", "Capital" => "Tokyo"]
];
for ($i = 0; $i < count($arr); $i++) {
    for ($j = $i + 1; $j < count($arr); $j++) {
        if (strcasecmp($arr[$i]["Country"], $arr[$j]["Country"]) > 0) {
            $temp = $arr[$i];
            $arr[$i] = $arr[$j];
            $arr[$j] = $temp;
        }
    }
}
echo "Country sorted in alphabetical order:<br>";
foreach ($arr as $countries) {
    echo "Country: {$countries["Country"]}, Capital: {$countries["Capital"]}<br>";
}
