// WAP to check if number input by user is prime or composite

import java.util.Scanner;

public class Nine {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Take Input
        System.out.println("Enter a number: ");
        int n = sc.nextInt();
        boolean isPrime = true;
        // Check If prime or not
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                // Not prime
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            System.out.println(n + " is prime number");
        } else {
            System.out.println(n + " is composite number");
        }
        sc.close();
    }
}