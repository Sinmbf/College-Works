package Sorting;

import java.util.Scanner;

public class SelectionSort {

    static int A[] = new int[100];
    static int n;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array: ");
        n = sc.nextInt();

        System.out.println("Enter Elements of araay: ");

        for (int i = 0; i < n; i++) {
            System.out.print("A[" + i + "] : ");
            A[i] = sc.nextInt();
        }

        System.out.println("Data Before Sorting: ");
        System.out.println("*********************");
        display();
        selectionSort();

        System.out.println("\nData After Sorting: ");
        System.out.println("*********************");
        display();
    }

    public static void selectionSort() {
        for (int i = 0; i < n - 1; i++) {
            int least = A[i];
            int loc = i;
            for (int j = i + 1; j < n; j++) {
                if (A[j] < least) {
                    least = A[j];
                    loc = j;
                }

            }

            A[loc] = A[i];
            A[i] = least;

        }
    }

    public static void display() {
        for (int i = 0; i < n; i++) {
            System.out.print(A[i] + "\t");
        }
    }

}
