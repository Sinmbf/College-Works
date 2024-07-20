/*

    Create a class Shape that contains instance variable length, breadth and height. Create a 
    default constructor that sets the value of instance variable to zero, constructor with 
    two parameter that will set the value of length and breadth only, constructor with 
    three parameter that will set the value of length, breadth and height. After this create
    calcAreaOfRectangle() that calculates the area of rectangle, calcVolumeOfBox() that 
    calculates volume of box and display the result. Now create first object of Shape which
    will have name rectangle and calls constructor with two parameter and calcAreaOfRectangle() 
    method, create second object of Shape that will have name box which will call constructor
    with three parameter and calcVolumeOfBox() method.

 */

class Shape {
    // Instance variable
    private int length;
    private int breadth;
    private int height;

    // Default Constructor
    public Shape() {
        this.length = 0;
        this.breadth = 0;
        this.height = 0;
        System.out.println("Instance variable set to 0");
    }

    // Parameterized constructor (two parameters)
    public Shape(int length, int breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    // Parameterized constructor (three parameters)
    public Shape(int length, int breadth, int height) {
        this.length = length;
        this.breadth = breadth;
        this.height = height;
    }

    // Method to calculate area of rectangle
    public int calcAreaOfRectangle() {
        return (this.length * this.breadth);
    }

    // Method to calculate volume of box
    public int calcVolumeOfBox() {
        return (this.length * this.breadth * this.height);
    }
}

public class Eight {
    public static void main(String[] args) {
        // Create object 1
        Shape defaultConstructor = new Shape();
        // Create object 2
        Shape rectangle = new Shape(5, 10);
        int areaOfRectangle = rectangle.calcAreaOfRectangle();
        // Create object 3
        Shape box = new Shape(5, 10, 20);
        int volumeOfBox = box.calcVolumeOfBox();
        // Display results
        System.out.println("Area of rectangle: " + areaOfRectangle);
        System.out.println("Volume of box: " + volumeOfBox);
    }
}
