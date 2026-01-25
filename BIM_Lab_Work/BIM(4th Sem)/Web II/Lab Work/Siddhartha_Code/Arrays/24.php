<!-- 24. Merge two numeric arrays and remove duplicate values without using array_unique(). -->

<?php
$arr1 = [1, 2, 3, 4, 5, 6];
$arr2 = [2, 3, 8, 9, 10];
$merged = [];
$result = [];

// Merge two array
foreach ($arr1 as $num) {
    $merged[] = $num; // append values of array 1
}
foreach ($arr2 as $num) {
    $merged[] = $num; // append values of array 2
}
// $merged = array_merge($arr1, $arr2);

// Remove duplicate
for ($i = 0; $i < count($merged); $i++) {
    $isDuplicate = false;
    for ($j = 0; $j < count($result); $j++) {
        if ($merged[$i] == $result[$j]) {
            $isDuplicate = true;
            break;
        }
    }
    if (!$isDuplicate) {
        $result[] = $merged[$i];
    }
}

// Display result
echo "After merging and removing duplicate: <br>";
foreach ($result as $num)
    echo $num . "<br>";
?>