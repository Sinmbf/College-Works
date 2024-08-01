// 4. Create an abstract class Calculation which has one normal method int
// add(int x, int y) which will calculate the sum of x and y and return the
// results and one abstract method int mul (int x, int y) that performs
// multiplication. Create a class Demo that inherit abstract class that
// implement all the abstract method, and it have its own method int calcDiv(int
// x, int y) that calculates the division between x and y and return the result.
// Now create the object of Demo and demonstrate the above scenario. After this
// access the method of abstract class using reference of abstract class.

// Abstract class
abstract class Calculation {
    // Normal method
    public int add(int x, int y) {
        return (x + y);
    }

    // Abstract method
    abstract int mul(int x, int y);
}

// Sub class (Child of abstract class)
class Demo extends Calculation {
    // Parent method
    public int mul(int x, int y) {
        return (x * y);
    }

    // Own method
    public int calcDiv(int x, int y) {
        return (x / y);
    }
}

// Main Class
public class Four {
    public static void main(String[] args) {
        // Create object of Demo
        Demo d1 = new Demo();
        // Call own method
        int division = d1.calcDiv(4, 2);
        // Call parent (abstract class) method
        int sum = d1.add(4, 5);
        int product = d1.mul(5, 6);
        // Display results
        System.out.println("Sum: " + sum);
        System.out.println("Product: " + product);
        System.out.println("Division: " + division);
    }
}