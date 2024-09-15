// WAP that asks the user to enter number in an array of size of "n". 
// then display only the numbers that are divisible by 2 and 3

import java.util.Scanner;

public class One {
    public static void main(String[] args) {
        // Create object
        Scanner sc = new Scanner(System.in);
        // Take size of array
        System.out.println("Enter the size of the array: ");
        int size = sc.nextInt();
        // Declare array
        int[] arr = new int[size];
        // Take elements of array
        System.out.println("Enter " + size + " elements: ");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        // Find elements divisible by 2 and 3
        System.out.println("Numbers divisible by 2 and 3: ");
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 == 0 && arr[i] % 3 == 0) {
                System.out.println(arr[i]);
            }
        }
        sc.close();
    }
}