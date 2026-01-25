<!-- 2. Write a PHP program to set and get private properties of a `Laptop` class using getter and setter methods. -->

<?php
class Laptop
{
    private $company_name;
    private $price;

    // Setter method
    public function setLaptop($company_name, $price)
    {
        $this->company_name = $company_name;
        $this->price = $price;
    }

    // Getter method
    public function getCompanyName()
    {
        return $this->company_name;
    }
    // Getter method
    public function getPrice()
    {
        return $this->price;
    }
}

$l = new Laptop();
$l->setLaptop("Asus", "80000");
$price = $l->getPrice();
$company_name = $l->getCompanyName();
echo "Laptop details:<br>Company Name: $company_name<br>Price: $price";

?>