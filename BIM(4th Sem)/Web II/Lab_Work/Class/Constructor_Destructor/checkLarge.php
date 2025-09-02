<?php   
    class Number{
        public $n1;
        public $n2;

        function __construct($n1,$n2){
            $this->n1=$n1;
            $this->n2=$n2;
        }

        function checkLarge($n1,$n2){
            echo "The largest is: ".(($this->n1>$this->n2)?$this->n1:$this->n2);
        }

        function __destruct(){
            echo "<br>Program ended";
        }
    }


    $num=new Number(55,103);
    $num->checkLarge($num->n1,$num->n2);

?>