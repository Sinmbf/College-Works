<!-- 18.Create a user-defined function to check whether a year is a leap year. -->

<?php
function checkLeapYear($year)
{

    if ($year % 4 == 0) {
        if ($year % 100 == 0) {
            if ($year % 400 == 0)
                echo "$year is a leap year";
            else
                echo "$year is not a leap year";
        } else {
            echo "$year is a leap year";
        }
    } else {
        echo "$year is not a leap year";
    }
}

$year = 2004;
checkLeapYear($year);
?>