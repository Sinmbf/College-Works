// WAP to demonstrate how to use bounds in generics.

// Bounds -> Used to restrict type that can be sent on method parameter, instance variable

class Rectangle<T extends Number, U extends Number> {
    // Instance Variable
    private T length;
    private U breadth;

    // Constructor
    public Rectangle(T length, U breadth) {
        this.length = length;
        this.breadth = breadth;

    }

    // Generic Method
    public void calcArea() {
        System.out.println("Area of rectangle: " + (this.length.intValue() * this.breadth.doubleValue()));
    }
}

// Main Class
public class Three {
    public static void main(String[] args) {
        // Create object
        Rectangle<Integer, Double> r1 = new Rectangle<>(10, 20.5);
        // Call generic method
        r1.calcArea();
    }
}
