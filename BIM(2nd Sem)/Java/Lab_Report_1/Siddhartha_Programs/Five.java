// WAP to demonstrate arithmetic operator, increment, decrement, comparison and Boolean Logical operator

public class Five {
    public static void main(String[] args) {
        int n1 = 10;
        int n2 = 11;
        // Arithmetic Operators
        System.out.println("Arithmetic Operations: ");
        System.out.println("Sum: " + (n1 + n2));
        System.out.println("Difference: " + (n1 - n2));
        System.out.println("Product: " + (n1 * n2));
        System.out.println("Quotient: " + (n1 / n2));
        System.out.println("Remainder: " + (n1 % n2));
        // Increment Operator
        System.out.println("Increment Operations: ");
        n1++;
        ++n1;
        System.out.println(n1);
        System.out.println("Decrement Operations: ");
        // Decrement Operator
        n2--;
        --n2;
        System.out.println(n2);
        // Comparison Operator
        System.out.println("Comparison Operations: ");
        if (n1 == n2) {
            System.out.println("First number equals second number");
        } else if (n1 >= n2) {
            System.out.println("First number greater than or equals second number");
        } else if (n1 != n2) {
            System.out.println("First number not equals second number");
        } else if (n1 <= n2) {
            System.out.println("First number less than or equals second number");
        }
        // Boolean Logical Operation
        System.out.println("Boolean Logical Operations: ");
        boolean a = true;
        boolean b = false;
        System.out.println("a XOR b: " + (a ^ b));
        System.out.println("a AND b: " + (a && b));
        System.out.println("a OR b: " + (a || b));
        System.out.println("NOT a: " + !(a));
    }
}
