// Make an array of integers of size 30 and store 30 integers in it.
// Then display the integers that are between 16 and 47

public class Two {
    public static void main(String[] args) {
        // Declare array of size 30
        int arr[] = {
                1, 34, 56, 89, 34, 54, 3, 43, 56, 87, 34, 40, 23, 45, 6, 32, 12, 22, 112, 98, 87,
                12, 23, 55, 53, 23, 78, 98, 47, 33
        };
        System.out.println("Size: " + arr.length);
        System.out.println("Array elements from 16 to 47: ");
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > 16 && arr[i] < 47) {
                System.out.print(arr[i] + "\t");
            }
        }

    }
}
