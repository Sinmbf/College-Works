// WAP to calculate sum, multiplication, division, subtraction of two number based on the user choice. 

import java.util.Scanner;

public class Seven {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Sum\n2. Multiplication\n3. Division\n4.Subtraction");
        System.out.println("Which operation do you want to perform?[1-4]: ");
        int choice = sc.nextInt();
        System.out.println("Enter two numbers: ");
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        switch (choice) {
            case 1:
                System.out.println("Sum: " + (n1 + n2));
                break;
            case 2:
                System.out.println("Multiplication: " + (n1 * n2));
                break;
            case 3:
                System.out.println("Division: " + ((double) n1 / n2));
                break;
            case 4:
                System.out.println("Subtraction: " + (n1 - n2));
                break;
            default:
                System.out.println("Invalid operation");
        }
        sc.close();
    }
}
