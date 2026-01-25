import java.util.Scanner;

public class ArrayDescending {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array: ");
        int size = sc.nextInt();
        System.out.println("Enter " + size + " elements: ");
        int[] arr = new int[size];
        for (int i = 0; i < 5; i++) {
            arr[i] = sc.nextInt();
        }
        // Arranging in descending order
        int temp=0;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (arr[i] < arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        // Display the array elements
        System.out.println("In descending order:");
        for (int i = 0; i < 5; i++) {
            System.out.println(arr[i]);
        }
        sc.close();
    }
}

