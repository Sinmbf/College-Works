// 1. Provide an example of single inheritance of your choice. (Two child class
// inheriting single parent class)

// Parent Class
class Shape {
    // Instance variable
    private String shapeName;

    // Method to set shape name
    public void setShapeName(String shapeName) {
        this.shapeName = shapeName;
    }

    // Method to display shape name
    public void displayShapeName() {
        System.out.println("Shape name: " + shapeName);
    }
}

// Child class 1
class Rectangle extends Shape {
    // Instance variable
    private int length;
    private int breadth;

    // Method to set instance variable
    public void setRectangle(int length, int breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    // Method to display details
    public void displayRectangle() {
        System.out.println("Length: " + length + "\nBreadth: " + breadth);
    }
}

// Child class 2
class Square extends Shape {
    // Instance variable
    private int length;

    // Method to set instance variable
    public void setSquare(int length) {
        this.length = length;
    }

    // Method to display details
    public void displaySquare() {
        System.out.println("Length: " + length);
    }
}

// Main Class
public class One {
    public static void main(String[] args) {
        // Create instance
        Rectangle r1 = new Rectangle();
        Square s1 = new Square();
        // Call own method
        r1.setRectangle(10, 20);
        s1.setSquare(4);
        // Call Parent method
        r1.setShapeName("Rectangle");
        s1.setShapeName("Square");
        r1.displayShapeName(); // Parent method
        // Own method
        r1.displayRectangle();
        s1.displayShapeName(); // Parent method
        s1.displaySquare(); // Own method
    }
}