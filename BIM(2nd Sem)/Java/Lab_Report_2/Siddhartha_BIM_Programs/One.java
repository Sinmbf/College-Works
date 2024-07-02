// WAP to take two number input from user, divide first number by second and display quotient and remainder obtained from division operation

import java.util.Scanner;

public class One {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Take input
        System.out.println("Enter two numbers: ");
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        double quotient = (double) n1 / n2;
        int rem = n1 % n2;
        System.out.println("Quotient: " + quotient + "\nRemainder: " + rem);
        sc.close();
    }
}