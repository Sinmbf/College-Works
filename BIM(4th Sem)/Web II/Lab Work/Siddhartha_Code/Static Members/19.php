<!-- 19. . Make a `Configuration` class that stores settings in static properties and display them without creating an object. -->

<?php
class Configuration
{
    // Static properties
    public static $appName = "MyApp";
    public static $version = "1.0.0";
    public static $timezone = "Asia/Kathmandu";
}

// Accessing static properties directly (without object)
echo Configuration::$appName . "<br>";
echo Configuration::$version . "<br>";
echo Configuration::$timezone;

?>