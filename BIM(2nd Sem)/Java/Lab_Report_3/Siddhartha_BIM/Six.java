// WAP to create multi-dimensional array of size m*n and insert integer value on it.
// Now display the element of array using for and for each loop

import java.util.Scanner;

public class Six {
    public static void main(String[] args) {
        // Create Object
        Scanner sc = new Scanner(System.in);
        // Take the size of multi-dim array
        System.out.println("Enter the no. of rows and columns in the array: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        // Declare multi-dim array
        int[][] arr = new int[m][n];
        System.out.println("Enter " + (m * n) + " elements: ");
        // Take elements for array
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        // Display array elements using for loop
        System.out.println("Elements of the array (Using for loop): ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(arr[i][j] + "\t");
            }
        }
        // Display array elements using for each loop
        System.out.println("\nElements of the array (Using for each loop)");
        for (int subArr[] : arr) {
            for (int element : subArr) {
                System.out.print(element + "\t");
            }
        }
        sc.close();
    }
}
