import java.util.Scanner;

public class SumOfMultiArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Take input
        System.out.println("Enter the number of rows and columns in array 1: ");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();
        System.out.println("Enter the number of rows and columns in array 2: ");
        int r2 = sc.nextInt();
        int c2 = sc.nextInt();
        if (r1 != r2 && c1 != c2) {
            System.out.println("Number of rows and columns must be same");
        } else {
            int[][] multiArr1 = new int[r1][c1];
            int[][] multiArr2 = new int[r2][c2];
            int[][] multiArrSum = new int[r2][c2];
            // Take values for array 1
            System.out.println("Enter " + (r1 * c1) + " values for array 1: ");
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                    multiArr1[i][j] = sc.nextInt();
                }
            }
            // Take values for array 2
            System.out.println("Enter " + (r2 * c2) + " values for array 2: ");
            for (int i = 0; i < r2; i++) {
                for (int j = 0; j < c2; j++) {
                    multiArr2[i][j] = sc.nextInt();
                    // Find sum
                    multiArrSum[i][j] = multiArr1[i][j] + multiArr2[i][j];
                }
            }
            // Display
            System.out.println("Sum of elements of both array:");
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                    System.out.println(multiArrSum[i][j]);
                }
            }
        }
        sc.close();
    }
}
