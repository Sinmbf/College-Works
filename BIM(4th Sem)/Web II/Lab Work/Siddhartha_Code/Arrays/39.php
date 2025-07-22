<!-- 39. Write a script to transpose a 3x3 matrix stored in a multidimensional array. -->

<?php
$matrix = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
];

$transpose = [];
echo "Transposed matrix:<br>";

// **** Using for each loop ****
// foreach ($matrix as $i => $rows) {
//     foreach ($rows as $j => $column) {
//         $transpose[$j][$i] = $column;
//     }
// }

// foreach ($transpose as $rows) {
//     foreach ($rows as $column)
//         echo "$column&nbsp;";
//     echo "<br>";
// }

// **** Using foreach loop ****
for ($i = 0; $i < 3; $i++) {
    for ($j = 0; $j < 3; $j++) {
        $transpose[$i][$j] = $matrix[$j][$i];
    }
}

for ($i = 0; $i < 3; $i++) {
    for ($j = 0; $j < 3; $j++)
        echo "{$transpose[$i][$j]}&nbsp;";
    echo "<br>";
}

?>