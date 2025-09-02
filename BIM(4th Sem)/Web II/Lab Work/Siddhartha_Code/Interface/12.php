<!-- 12. Create an interface `Logger` with `logInfo()` and `logError()` methods and implement it in two classes: `FileLogger` and `DatabaseLogger`. -->

<?php
// Define the Logger interface
interface Logger
{
    public function logInfo($message);
    public function logError($message);
}

// FileLogger implementation
class FileLogger implements Logger
{
    private $filename;

    public function __construct($filename)
    {
        $this->filename = $filename;
    }

    public function logInfo($message)
    {
        echo "Writing INFO to file {$this->filename}: $message<br>";
        // In real-world: file_put_contents($this->filename, "[INFO] $message\n", FILE_APPEND);
    }

    public function logError($message)
    {
        echo "Writing ERROR to file {$this->filename}: $message<br>";
        // In real-world: file_put_contents($this->filename, "[ERROR] $message\n", FILE_APPEND);
    }
}

// DatabaseLogger implementation
class DatabaseLogger implements Logger
{
    private $connection;

    public function __construct($connection)
    {
        $this->connection = $connection; // e.g., mysqli or PDO
    }

    public function logInfo($message)
    {
        echo "Inserting INFO log into database: $message<br>";
        // In real-world: $this->connection->query("INSERT INTO logs (type, message) VALUES ('INFO', '$message')");
    }

    public function logError($message)
    {
        echo "Inserting ERROR log into database: $message<br>";
        // In real-world: $this->connection->query("INSERT INTO logs (type, message) VALUES ('ERROR', '$message')");
    }
}

// Usage
$fileLogger = new FileLogger("app.log");
$dbLogger = new DatabaseLogger("FakeDBConnection");

// Test file logger
$fileLogger->logInfo("Application started");
$fileLogger->logError("File not found");

// Test database logger
$dbLogger->logInfo("User logged in");
$dbLogger->logError("Database connection failed");
?>