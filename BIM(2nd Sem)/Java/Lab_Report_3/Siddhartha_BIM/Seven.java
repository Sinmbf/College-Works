// WAP to create two multi-dimensional array of size m*n and insert integer value on it.
// Perform multiplication operation and store the result in third array and display the 
// content of third array.

import java.util.Scanner;

public class Seven {
    public static void main(String[] args) {
        // Create Object
        Scanner sc = new Scanner(System.in);
        // Take the size of array 1
        System.out.println("Enter the no. of rows and columns in array 1: ");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();
        // Take the size of array 2
        System.out.println("Enter the no. of rows and columns in array 2: ");
        int r2 = sc.nextInt();
        int c2 = sc.nextInt();
        if (r1 != r2 || c1 != c2) {
            System.out.println("Multiplication not possible. Rows and columns of both array must be same!");
        } else {
            // Declare array
            int[][] arr1 = new int[r1][c1];
            int[][] arr2 = new int[r2][c2];
            int[][] arrProduct = new int[r2][c2];
            // Take values for array 1
            System.out.println("Enter " + (r1 * c1) + " elements for array 1: ");
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                    arr1[i][j] = sc.nextInt();
                }
            }
            // Take values for array 2
            System.out.println("Enter " + (r2 * c2) + " elements for array 2: ");
            for (int i = 0; i < r2; i++) {
                for (int j = 0; j < c2; j++) {
                    arr2[i][j] = sc.nextInt();
                    // Perform multiplication
                    arrProduct[i][j] = arr1[i][j] * arr2[i][j];
                }
            }
            // Display the result
            System.out.println("After multiplication: ");
            // for (int i = 0; i < r2; i++) {
            // for (int j = 0; j < c2; j++) {
            // System.out.print(arrProduct[i][j] + "\t");
            // }
            // }
            for (int subArr[] : arrProduct) {
                for (int element : subArr) {
                    System.out.print(element + "\t");
                }
            }
            sc.close();
        }
    }
}
