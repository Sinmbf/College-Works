// WAP to demonstrate arithmetic operator, increment, decrement, comparison and Boolean Logical operator

public class Five {
    public static void main(String[] args) {
        int n1 = 10;
        int n2 = 11;
        char ch = 'a';
        // Arithmetic Operators
        int sum = n1 + n2;
        int difference = n1 - n2;
        int product = n1 * n2;
        int quotient = n1 / n2;
        int rem = n1 % n2;
        System.out.println("Arithmetic Operations: ");
        System.out.println("Sum: " + sum);
        System.out.println("Difference: " + difference);
        System.out.println("Product: " + product);
        System.out.println("Quotient: " + quotient);
        System.out.println("Remainder: " + rem);
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
            System.out.println("First number greater than second number");
        } else if (n1 != n2) {
            System.out.println("First number not equals second number");
        } else if (n1 <= n2) {
            System.out.println("First number less than second number");
        }
        // Boolean Logical Operation
        System.out.println("Boolean Logical Operations: ");
        String checkChar = (ch >= 'a' && ch <= 'z') ? "Small letter alphabet"
                : (ch == 'a' || ch == 'e') ? "Vowel letter" : "Not an alphabet";
        System.out.println("AND OR Operation: ");
        System.out.println(checkChar);
        System.out.println("Logical XOR operation: ");
        boolean a = true;
        boolean b = false;
        boolean result = (a ^ b);
        System.out.println("a XOR b: " + result);
    }
}
