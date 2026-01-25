<!-- 3. Create a class `BankAccount` with deposit and withdraw methods and display the balance. -->

<?php
class BankAccount
{
    private $balance = 0;

    public function deposit($amount)
    {
        $this->balance = $amount;
        echo "$amount deposited successfully";
    }

    public function withdraw($amount)
    {
        if ($amount > $this->balance) {
            echo "<br>Can't withdraw $amount. Balance insufficient";
        } else {

            $this->balance -= $amount;
            echo "<br>$amount withdrawn";
        }
    }

    public function showBalance()
    {
        echo "<br>Current Balance: $this->balance";
    }
}

$b = new BankAccount();
$b->deposit(20000);
$b->showBalance();
$b->withdraw(15000);
$b->showBalance();
?>