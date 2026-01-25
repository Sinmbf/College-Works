package Sorting;

import java.util.Scanner;

public class InsertionSort {

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
        insertionSort();

        System.out.println("\nData After Sorting: ");
        System.out.println("*********************");
        display();
    }

    public static void insertionSort() {
        int key = 0, j = 0;
        for (int i = 1; i < n; i++) {
            key = A[i];

            for (j = i - 1; j >= 0 && A[j] > key; j--) {
                A[j + 1] = A[j];
            }
            A[j + 1] = key;
        }

    }

    public static void display() {
        for (int i = 0; i < n; i++) {
            System.out.print(A[i] + "\t");
        }
    }

}
