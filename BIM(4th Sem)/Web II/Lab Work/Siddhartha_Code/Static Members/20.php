<!-- 20. Create a class `Database` with a static method `getConnection()` that simulates a database connection (singleton pattern idea). -->

<?php
/* 
The Singleton pattern ensures that only one instance of the database connection is created and reused, rather than creating a new connection every time getConnection() is called.
*/
class Database
{
    private static $conn = null;

    // Get the single database connection
    public static function getConnection($server, $username, $password)
    {
        if (self::$conn === null) {
            // Connect to MySQL server (without specifying database yet)
            self::$conn = new mysqli($server, $username, $password);

            if (self::$conn->connect_error) {
                die("Database connection failed: " . self::$conn->connect_error);
            }

            echo "<br>Connected to MySQL server successfully.";

            // Create the database "user" if it doesn't exist
            $sql = "CREATE DATABASE IF NOT EXISTS user";
            if (self::$conn->query($sql) === TRUE) {
                echo "<br>Database 'user' created successfully.";
            } else {
                die("<br>Error creating database: " . self::$conn->error);
            }

            // Now select the database for further operations
            self::$conn->select_db("user");
        }

        return self::$conn;
    }
}

// Usage
$conn = Database::getConnection("localhost", "root", "");
?>