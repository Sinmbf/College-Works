// 6. Create an abstract class Calculator having abstract methods calcPrime(int
// x, int y), calcEven(int x, int y). Now create a class SimpleCalculator that
// inherit an abstract class and provide the implementation of abstract method

// Abstract class
abstract class Calculator {
    // Abstract methods
    abstract void calcPrime(int x, int y);

    abstract void calcEven(int x, int y);
}

// Normal Class (Child of abstract class)
class SimpleCalculator extends Calculator {
    // Parent (abstract) class method
    // Method to calculate prime numbers from x to y
    public void calcPrime(int x, int y) {
        // Swap if first number greater than second
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        System.out.println("Prime numbers from " + x + " to " + y + ":");
        for (int i = x; i <= y; i++) {
            boolean isPrime = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    // Not prime
                    isPrime = false;
                    break;
                }
            }
            if (isPrime && i != 1) {
                System.out.print(i + "\t");
            }
        }
    }

    // Method to calculate even numbers from x to y
    public void calcEven(int x, int y) {
        // Swap if first number greater than second
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        System.out.println("\nEven numbers from " + x + " to " + y + ":");
        for (int i = x; i <= y; i++) {
            if (i % 2 == 0) {
                System.out.print(i + "\t");
            }
        }
    }
}

// Main Class
public class Six {
    public static void main(String[] args) {
        // Create instance(object)
        SimpleCalculator sc = new SimpleCalculator();
        // Call methods
        sc.calcPrime(1, 50);
        sc.calcEven(1, 10);
    }
}
