<!-- 5.	Create a pyramid pattern using nested for loops in PHP. -->

<?php

echo "<pre>";
for ($i = 1; $i <= 5; $i++) {
    for ($j = 4; $j >= $i; $j--) {
        echo " ";
    }
    for ($k = 1; $k <= $i; $k++) {
        echo "* ";
    }
    echo "<br>";
}
echo "</pre>";

?>