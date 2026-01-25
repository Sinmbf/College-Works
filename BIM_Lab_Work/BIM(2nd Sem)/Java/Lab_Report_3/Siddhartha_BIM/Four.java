// WAP to create integer array of size 'n' and insert 'n' data on it. Now display the element
// of array that are in even position.

import java.util.Scanner;

public class Four {
    public static void main(String[] args) {
        // Create object
        Scanner sc = new Scanner(System.in);
        // Take the size of the array
        System.out.println("Enter the size of the array: ");
        int size = sc.nextInt();
        // Declare array
        int[] arr = new int[size];
        // Take elements of array
        System.out.println("Enter " + size + " elements: ");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        // Display elements in even position
        System.out.println("Elements in even position: ");
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                System.out.println(arr[i]);
            }
        }
        sc.close();
    }
}