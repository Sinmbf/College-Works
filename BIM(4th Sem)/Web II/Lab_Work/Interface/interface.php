<?php
    interface A{
        public function getData();
        public function calcLength();
    }

    class B implements A{
        public $l;
        public $b;

        public function getData(){
            $this->l=20;
            $this->b=30;
        }

        public function calcLength(){
            echo "Length of rectangle: ".(2*($this->l+$this->b));
        }
    }

    $b=new B();
    $b->getData();
    $b->calcLength();

?>



