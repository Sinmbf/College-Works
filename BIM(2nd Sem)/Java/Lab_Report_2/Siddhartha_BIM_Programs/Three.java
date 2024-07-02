/* Solve the following using ternary operator:

    a) Read a number from user and print whether number is odd or even
    b) Read a number from user and print whether that number is positive or negative
    c) Read three numbers from user and find greatest of them

*/

import java.util.Scanner;

public class Three {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Take input
        System.out.println("Enter a number: ");
        int n1 = sc.nextInt();
        // Check if even or odd
        String result = (n1 % 2 == 0) ? (n1 + " is even") : (n1 + " is odd");
        System.out.println(result);
        // Check if negative or positive
        System.out.println("Enter a number: ");
        n1 = sc.nextInt();
        result = (n1 > 0) ? (n1 + " is positive") : (n1 + " is negative");
        System.out.println(result);
        // Find the greatest among three
        System.out.println("Enter three numbers: ");
        n1 = sc.nextInt();
        int n2 = sc.nextInt();
        int n3 = sc.nextInt();
        result = (n1 > n2 && n1 > n3) ? (n1 + " is the greatest")
                : (n2 > n1 && n2 > n3) ? (n2 + " is the greatest") : (n3 + " is the greatest");
        System.out.println(result);
        sc.close();
    }
}