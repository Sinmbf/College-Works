// WAP to demonstrate implicit and explicit type casting

public class Four {
    public static void main(String[] args) {
        int n1 = 1;
        int n2 = 2;
        // Implicit Typecasting (int to double)
        double res1 = n1 / n2; // Here, n1 and n2 are integers. So result is in integer
        // Explicit Typecasting (float to int)
        float f1 = 100.5f;
        int n3 = (int) f1;
        System.out.println("Integer to double: " + res1);
        System.out.println("Float to integer: " + n3);
    }
}
