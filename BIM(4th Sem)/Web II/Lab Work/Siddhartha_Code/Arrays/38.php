<!-- 38. Create a library record system where each book has title, author, and available copies. Find books with less than 2 copies. -->

<?php
$library = [
    ["Title" => "Rich Dad Poor Dad", "Author" => "Robert T. Kiyosaki", "Copies" => 3],
    ["Title" => "Atomic Habits", "Author" => "James Clear", "Copies" => 5],
    ["Title" => "The Silent Patient", "Author" => "Alex Michaelides", "Copies" => 0],
    ["Title" => "Digital Minimalism", "Author" => "Cal Newport", "Copies" => 5],
    ["Title" => "Ikigai", "Author" => "Hector Garcia", "Copies" => 1],
];

echo "Books with less than 2 copies:<br>";
foreach ($library as $books) {
    if ($books["Copies"] < 2)
        echo "Title: {$books["Title"]}, Author: {$books["Author"]}<br>";
}
?>