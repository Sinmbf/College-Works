<!--  4.Write a PHP program to demonstrate constructor and destructor in a `Mobile` class. -->

<?php

class Mobile
{
    public $company;
    public $price;

    public function __construct($company, $price)
    {
        $this->company = $company;
        $this->price = $price;
    }

    public function showDetails()
    {
        echo "Company: $this->company<br>Price: $this->price";
    }

    public function __destruct()
    {
        echo "<br>End program";
    }
}

$m = new Mobile("Samsung", 20000);
$m->showDetails();
?>