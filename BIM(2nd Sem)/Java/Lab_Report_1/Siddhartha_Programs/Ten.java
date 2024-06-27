// WAP to check whether input given by user is even or odd

import java.util.Scanner;

public class Ten {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Take Input
        System.out.println("Enter a number: ");
        int n = sc.nextInt();
        String res = (n % 2 == 0) ? (n + " is even") : (n + " is odd");
        System.out.println(res);
        sc.close();
    }
}
