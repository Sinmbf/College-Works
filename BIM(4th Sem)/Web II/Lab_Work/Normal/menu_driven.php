<?php   
    echo "1. Find area of rectangle <br>";
    echo "2. Find area of circle <br>";
    echo "3. Find area of triangle <br>";
    $choice=2;
    switch($choice){
        case 1:
            $length=20;
            $breadth=30;
            echo "Area of rectangle: ".($length*$breadth);
            break;

        case 2:
            $radius=3;
            echo "Area of circle: ".(3.1415*$radius*$radius);
            break;

        case 3:
            $height=20;
            $breadth=30;
            echo "Area of triangle: ".(0.5*$height*$breadth);
            break;
        
        default:
            echo "Invalid choice";
    }
?>