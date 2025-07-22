<!-- 35. Represent an inventory system using a multidimensional array (product name, quantity, price). Print stock value of each product. -->

<?php
$arr = [
    ["Name" => "Fan", "Quantity" => 20, "Price" => 5000],
    ["Name" => "Mobile", "Quantity" => 15, "Price" => 30000],
    ["Name" => "Laptop", "Quantity" => 10, "Price" => 80000],
    ["Name" => "Fridge", "Quantity" => 5, "Price" => 35000],
];

foreach ($arr as $product) {
    $stock_value = $product["Quantity"] * $product["Price"];
    echo "Stock value of {$product["Name"]}: Rs. $stock_value<br>";
    $stock_value = 1;
}

?>