// 7.	Create a class named Shape with a method to print “this is shape”. Then create two other class named “Rectangle” and “circle” inheriting the class Shape both having method to print “this is rectangular” and “this is circular”. Create subclass Square that now inherits Rectangle which have its own method to display “this is square of rectangle”. Now call the method of Shape and Rectangle class by the object of square class inside the class having main method. 

// Parent class
class Shape {
    // Method to print
    public void displayMessage1() {
        System.out.println("This is shape");
    }
}

// Child class 1
class Rectangle extends Shape {
    // Method to display message
    public void displayMessage2() {
        System.out.println("This is rectangular");
    }
}

// Child class 2
class Circle extends Shape {
    // Method to display message
    public void displayMessage3() {
        System.out.println("This is circular");
    }
}

// Grandchild 1
class Square extends Rectangle {
    // Method to display message
    public void displayMessage4() {
        System.out.println("This is square of rectangle");
    }
}

// Main Class
public class Seven {
    public static void main(String[] args) {
        // Create object of grand child
        Square sq = new Square();
        sq.displayMessage1();
        sq.displayMessage2();
    }
}
