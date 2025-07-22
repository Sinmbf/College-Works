<!-- 29. Create an associative array of countries and their capitals. Display them alphabetically by country name. -->

<?php
$arr = ["Nepal" => "Kathmandu", "India" => "New Delhi", "United States" => "Washington DC", "France" => "Paris", "Japan" => "Tokyo"];

// Sort by keys of associative array
ksort($arr);
echo "Sorted in alphabetical order by country name:<br>";
foreach ($arr as $country_name => $capital)
    echo "Country: $country_name, Capital:$capital<br>";
// Create two indexed arrays of country and capital
// $keys = array_keys($arr);
// $values = array_values($arr);
// $length = count($keys);
// for ($i = 0; $i < $length - 1; $i++) {
//     for ($j = $i + 1; $j < $length; $j++) {
//         if (strcmp($keys[$i], $keys[$j]) > 0) {
//             $temp = $keys[$i];
//             $keys[$i] = $keys[$j];
//             $keys[$j] = $temp;

//             $temp2 = $values[$i];
//             $values[$i] = $values[$j];
//             $values[$j] = $temp2;
//         }
//     }
// }

// for ($i = 0; $i < $length; $i++) {
//     echo "Country: $keys[$i], Capital: $values[$i]<br> ";
// }
?>