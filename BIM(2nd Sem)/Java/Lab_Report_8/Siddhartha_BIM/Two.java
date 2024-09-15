// WAP to demonstrate how to use generics with different types.

class Rectangle<T, U> {
    // Instance Variable
    private T length;
    private U breadth;

    // Constructor
    public Rectangle(T length, U breadth) {
        this.length = length;
        this.breadth = breadth;

    }

    // Generic Method
    public T getLength() {
        return this.length;
    }

    public U getBreadth() {
        return this.breadth;
    }
}

// Main Class
public class Two {
    public static void main(String[] args) {
        // Create object
        Rectangle<Integer, Double> r1 = new Rectangle<>(10, 20.5);
        // Call generic method
        int l1 = r1.getLength();
        double b1 = r1.getBreadth();
        System.out.println("Length: " + l1 + "\nBreadth: " + b1);
    }
}
