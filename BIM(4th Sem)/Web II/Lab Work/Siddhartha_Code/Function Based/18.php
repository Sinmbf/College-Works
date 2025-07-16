<!-- 18.Create a user-defined function to check whether a year is a leap year. -->

<?php
function checkLeapYear($year)
{

    if ($year % 4 == 0 && $year%100!=0) 
        echo "$year is a leap year";
    else if($year%400==0)
        echo "$year is a leap year";
    else {
        echo "$year is not a leap year";
    }
}
$year = 2026;
checkLeapYear($year);
?>
