// WAP to show how integer and string input can be taken from user.

import java.util.Scanner;

public class Eight {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Integer Input
        System.out.println("Enter an integer: ");
        int n = sc.nextInt();
        // String Input
        System.out.println("Enter a string: ");
        String str = sc.next();
        // Display
        System.out.println("Integer: " + n);
        System.out.println("String: " + str);
        sc.close();
    }
}
