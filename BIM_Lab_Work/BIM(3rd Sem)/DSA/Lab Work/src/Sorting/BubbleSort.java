package Sorting;

import java.util.Scanner;

public class BubbleSort {

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
            System.out.println();
        }

        System.out.println("Data Before sorting: ");
        System.out.println("*********************");
        display();
        bubbleSort();

        System.out.println("\nData After sorting: ");
        System.out.println("*********************");
        display();
    }

    public static void bubbleSort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (A[j] > A[j + 1]) {
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }

            }

        }
    }

    public static void display() {
        for (int i = 0; i < n; i++) {
            System.out.print(A[i] + "\t");
        }
    }

}
