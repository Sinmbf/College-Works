<!-- 11. Write a PHP program with an interface `Printable` that forces implementing classes (`Book`, `Magazine`) to define a `printDetails()` method. -->

<?php

interface Printable
{
    public function printDetails();
}

class Book implements Printable
{
    public $book_name;
    public $book_price;

    public function __construct($book_name, $book_price)
    {
        $this->book_name = $book_name;
        $this->book_price = $book_price;
    }

    public function printDetails()
    {
        echo "Details of book:<br> Name: $this->book_name<br>Price: $this->book_price<br>";
    }
}
class Magazine implements Printable
{
    public $magazine_name;
    public $magazine_price;

    public function __construct($magazine_name, $magazine_price)
    {
        $this->magazine_name = $magazine_name;
        $this->magazine_price = $magazine_price;
    }

    public function printDetails()
    {
        echo "Details of magazine:<br> Name: $this->magazine_name<br>Price: $this->magazine_price<br>";
    }
}

$b = new Book("Atomic Habit", "20$");
$m = new Magazine("New Times", "10$");
$b->printDetails();
$m->printDetails();
?>