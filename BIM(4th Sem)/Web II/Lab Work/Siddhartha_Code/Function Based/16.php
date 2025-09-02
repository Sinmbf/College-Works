<!-- 16. Build a function that converts temperature from Celsius to Fahrenheit. -->

<?php

function celsiusToFahrenheit($celsius)
{
    return $celsius * (9 / 5) + 32;
}
$celsius = 52;
echo "$celsius Celsius to Fahrenheit: " . celsiusToFahrenheit($celsius);
?>