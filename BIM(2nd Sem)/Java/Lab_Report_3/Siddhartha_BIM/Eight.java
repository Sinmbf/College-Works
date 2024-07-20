// WAP to demonstrate jagged array

/*

    A jagged array, also known as a "ragged array," is an array of arrays where the inner arrays   can have different lengths. In Java, jagged arrays are essentially arrays of arrays, and  they allow you to create structures where each row can have a different number of elements.

 */

public class Eight {
    public static void main(String[] args) {
        // Declare a jagged array
        int[][] jaggedArray = new int[2][];
        // Initialize the rows with different lengths
        jaggedArray[0] = new int[2]; // First row has length 2
        jaggedArray[1] = new int[3]; // Second row has length 3
        // Input values int row 1
        jaggedArray[0][0] = 2;
        jaggedArray[0][1] = 3;

        // Input values int row 2
        jaggedArray[1][0] = 4;
        jaggedArray[1][1] = 5;
        jaggedArray[1][2] = 6;
        // Display elements
        System.out.println("Elements of the jagged array: ");
        for (int i = 0; i < jaggedArray.length; i++) {
            System.out.println("Elements in row " + (i + 1) + ": ");
            for (int j = 0; j < jaggedArray[i].length; j++) {
                System.out.println(jaggedArray[i][j]);
            }
        }
    }
}
