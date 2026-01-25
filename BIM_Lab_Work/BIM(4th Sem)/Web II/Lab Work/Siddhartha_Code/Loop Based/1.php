<!-- 1.	Write a PHP script to print the first 10 even numbers using a while loop. -->

<?php
$i = 0; // the numbers to be checked
$count = 10; // to keep track of even numbers count
echo "First $count even numbers:<br>";
while ($count != 10) { // print 10 even numbers
    if ($i % 2 == 0) {
        echo "$i<br>"; // print if even
        $count--; // increment even count
    }
    $i++; // Check next number
}

?>
