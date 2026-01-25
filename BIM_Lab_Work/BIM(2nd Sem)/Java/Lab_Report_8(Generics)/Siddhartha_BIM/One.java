// WAP to demonstrate how to use generics.

class Rectangle<T> {
    // Instance Variable
    private T length;
    private T breadth;

    // Constructor
    public Rectangle(T length, T breadth) {
        this.length = length;
        this.breadth = breadth;

    }

    // Generic Method
    public T getLength() {
        return this.length;
    }

    public T getBreadth() {
        return this.breadth;
    }
}

// Main Class
public class One {
    public static void main(String[] args) {
        // Create object
        Rectangle<Integer> r1 = new Rectangle<>(10, 20);
        // Call generic method
        int l1 = r1.getLength();
        int b1 = r1.getBreadth();
        System.out.println("Length: " + l1 + "\nBreadth: " + b1);
    }
}
