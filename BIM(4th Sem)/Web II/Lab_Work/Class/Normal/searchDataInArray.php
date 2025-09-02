<!-- WAP to search data in array using class -->

<?php
class Number
{
    public $arr;

    function __construct($arr){
        $this->arr=$arr;
    }

    function searchElement($key)
    {
        $flag = 0;
        for ($i = 0; $i < count($this->arr); $i++) {
            if ($this->arr[$i] == $key) {
                echo "Element found at position: " . ($i + 1);
                $flag = 1;
                break;
            }
        }
        if ($flag == 0) {
            echo "Element not found";
        }
    }
}

$n = new Number([1,2,3,4,5]);
$n->searchElement(5);

?>