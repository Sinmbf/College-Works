// WAP to take string input from user and if the length of such string is prime number then
// insert that string into file "prime.txt" otherwise, write into file "composite.txt"

import java.util.Scanner;
import java.io.*;

public class Five {
    public static void main(String[] args) {
        // Create Scanner object
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String str = sc.nextLine();
        int strLength = str.length();
        // Perform file operation
        try {
            boolean isPrime = true;
            for (int i = 2; i < strLength; i++) {
                if (strLength % i == 0) {
                    isPrime = false; // Not prime
                    break;
                }
            }
            if (strLength == 1) {
                System.out.println("Length: " + strLength + " which is neither prime nor composite");
            } else if (isPrime) {
                // Open file for writing
                FileWriter fwPrime = new FileWriter("prime.txt");
                System.out.println("Length is: " + strLength + " which is a prime number. So write into prime.txt");
                // Write into prime.txt
                fwPrime.write(str);
                fwPrime.close();
            } else {
                // Open file for writing
                FileWriter fwComposite = new FileWriter("composite.txt");
                System.out.println(
                        "Length is: " + strLength + " which is a composite number. So write into composite.txt");
                // Write into composite.txt
                fwComposite.write(str);
                fwComposite.close();
            }
            sc.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
