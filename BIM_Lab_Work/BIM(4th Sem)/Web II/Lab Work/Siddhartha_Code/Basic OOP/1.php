<!--  1.Create a PHP class `Book` with title, author, and price properties, and a method to display book details. -->

<?php
class Book
{
    public $title;
    public $author;
    public $price;


    function __construct($title, $author, $price)
    {
        $this->title = $title;
        $this->price = $price;
        $this->author = $author;
    }

    function showDetails()
    {
        echo "Title: $this->title<br>Author: $this->author<br>Price: $this->price<br>";
    }
}

$b = new Book("The Alchemist", "Paulo Coelho", "Rs 1200");
echo "Details of the book:<br>";
$b->showDetails();
?>