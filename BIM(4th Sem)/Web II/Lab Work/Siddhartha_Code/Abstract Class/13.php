<!-- 13. Write an abstract class `Animal` with an abstract method `sound()`. Implement it in `Dog` and `Cat` classes. -->

<?php

abstract class Animal
{
    abstract function sound();
}

class Dog extends Animal
{
    function sound()
    {
        echo "Dog sound: vow vow!";
    }
}


class Cat extends Animal
{
    function sound()
    {
        echo "<br>Cat sound: meow meow!";
    }
}

$d = new Dog();
$c = new Cat();
$d->sound();
$c->sound();
?>