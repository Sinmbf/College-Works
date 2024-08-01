// 1.	Create a class Work which consist of three methods with same name calculate (). If two parameters is passed calculate the sum between two parameter and display the result, if three parameter of type double is passed then find the multiplication between three parameter and return the result, if two parameter of float is passed then calculate difference between two parameter and display the result. Now create the instance of Work and invoke all the method to demonstrate method overloading condition.

class Work {
    // Method that adds
    public void calculate(int n1, int n2) {
        System.out.println(n1 + " + " + n2 + ": " + (n1 + n2));
    }

    // Method that return product
    public double calculate(double n1, double n2, double n3) {
        return (n1 * n2 * n3);
    }

    // Method that subtracts
    public void calculate(float n1, float n2) {
        System.out.println(n1 + " - " + n2 + ": " + (n1 - n2));
    }
}

// Main Class
public class One {
    public static void main(String[] args) {
        // Create instance of Work
        Work w1 = new Work();
        // Call methods
        w1.calculate(30, 40);
        double product = w1.calculate(3.2, 3.4, 3.9);
        w1.calculate(2.4f, 2.6f);
        // Display result
        System.out.println("Product: " + product);
    }
}