<!-- 30. Create an associative array with product names as keys and prices as values. Apply a 10% discount to all products and print updated prices. -->

<?php
$arr = ["Fan" => 2000, "Mobile" => 20000, "Computer" => 80000, "Helmet" => "5500", "Shoes" => 4500];
$discount = 0.1; // 10% discount
echo "Updated price after discount:<br>";
foreach ($arr as $product => $price) {
    $arr[$product] = $price - $price * $discount;
    echo "$product => Rs $arr[$product]<br>";
}
?>