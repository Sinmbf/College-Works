// 3.	How static polymorphism is achieved in java? Show a program

class Calculation {
    // Static polymorphism (Method Overloading) => Same method name but different function
    // Method to find sum
    public void calculate(int n1, int n2) {
        System.out.println(n1 + " + " + n2 + ": " + (n1 + n2));
    }
    // Method to find product
    public void calculate(double n1, double n2) {
        System.out.println(n1 + " * " + n2 + ": " + (n1 * n2));
    }
}

public class Three {
    public static void main(String[] args) {
        // Create instance
        Calculation c1 = new Calculation();
        // Call method
        c1.calculate(30, 40);
        c1.calculate(2.5, 4.5);
    }
}