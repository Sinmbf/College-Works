<!-- 10. Create an interface `Payment` with methods `pay()` and `refund()`. Implement it in `CreditCard` and `PayPal` classes. -->

<?php

interface Payment
{
    public function pay($amount);
    public function refund($amount);
}

class CreditCard implements Payment
{
    public function pay($amount)
    {
        echo "Paid Rs $amount through credit card<br>";
    }

    public function refund($amount)
    {
        echo "Refunded Rs $amount through credit card<br>";
    }
}
class PayPal implements Payment
{
    public function pay($amount)
    {
        echo "Paid Rs $amount through paypal<br>";
    }

    public function refund($amount)
    {
        echo "Refunded Rs $amount through paypal<br>";
    }
}

$cc = new CreditCard();
$pp = new PayPal();
$cc->pay(20000);
$cc->refund(10000);
$pp->pay(15000);
$pp->refund(5000);
?>