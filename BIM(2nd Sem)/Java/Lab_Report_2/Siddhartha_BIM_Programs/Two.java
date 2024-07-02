/*  WAP to read four digit number from user and perform following operation

    a) Display each digit separately
    b) Print the sum of digits
    c) Reverse the digits
    d) Find the sum of square of each digit

*/

import java.util.Scanner;

public class Two {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Take input
        System.out.println("Enter a four-digit number: ");
        int fourDigitNum = sc.nextInt();
        int num = fourDigitNum;
        int div = 1000;
        int sum = 0;
        int rev = 0;
        int sumSquare = 0;
        // Display each digit separately
        System.out.println("Each Individual Digit:");
        while (num != 0) {
            int individualDigit = fourDigitNum / div;
            int rem = num % 10;
            rev = rev * 10 + rem;
            fourDigitNum = fourDigitNum % div;
            num /= 10;
            div /= 10;
            sum += individualDigit;
            sumSquare += individualDigit * individualDigit;
            System.out.println(individualDigit);
        }
        // Print the sum of digits
        System.out.println("Sum of digits: " + sum);
        // Reverse the digits
        System.out.println("Reverse of digits: " + rev);
        // Find the sum of square of each digit
        System.out.println("Sum of square of each digit: " + sumSquare);
        sc.close();
    }
}