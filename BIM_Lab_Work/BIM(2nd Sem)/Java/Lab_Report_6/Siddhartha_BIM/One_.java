// 1. Provide an example of single inheritance of your choice. (Two child class
// inheriting single parent class)

// Parent Class
class Shape {
    // Instance variable
    private String shapeName;

    // Method to set instance variable
    public void setShapeName(String shapeName) {
        this.shapeName = shapeName;
    }

    // Method to display shape name
    public void displayShapeName() {
        System.out.println("Shape name: " + shapeName);
    }
}

// Child class 1
class Triangle extends Shape {
    // Instance variable
    private int breadth;
    private int height;

    // Method to set instance variable
    public void setTriangle(int breadth, int height) {
        this.breadth = breadth;
        this.height = height;
    }

    // Method to calculate area
    public void calcArea() {
        System.out.println("Area of triangle: " + (0.5 * breadth * height));
    }

}

// Child class 2
class Rectangle extends Shape {
    // Instance variable
    private int length;
    private int breadth;

    // Method to set instance variable
    public void setRectangle(int length, int breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    // Method to calculate area
    public void calcArea() {
        System.out.println("Area of rectangle: " + (length * breadth));
    }

}

// Main Class
public class One_ {
    public static void main(String[] args) {
        // Create instance(object)
        Triangle t1 = new Triangle();
        Rectangle r1 = new Rectangle();

        // Parent Method
        t1.setShapeName("Triangle");
        r1.setShapeName("Rectangle");
        // Own Method
        t1.setTriangle(3, 4);
        r1.setRectangle(5, 6);
        t1.displayShapeName(); // Parent method
        t1.calcArea();
        r1.displayShapeName(); // Parent Method
        r1.calcArea();
    }
}