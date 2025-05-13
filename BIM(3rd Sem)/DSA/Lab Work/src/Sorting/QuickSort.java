package Sorting;

import java.util.Scanner;

public class QuickSort {

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

        quickSort(0, n - 1);

        System.out.println("\nData After Sorting: ");
        System.out.println("*********************");
        display();
    }

    public static void display() {
        for (int i = 0; i < n; i++) {
            System.out.print(A[i] + "\t");
        }
    }

    private static void quickSort(int l, int r) {
        if (l < r) {
            int p = partition(l, r);
            quickSort(l, p - 1);
            quickSort(p + 1, r);
        }
    }

    private static int partition(int l, int r) {
        int x = l;
        int y = r;
        int pivot = A[l];
        while (x < y) {
            while (A[x] <= pivot) {
                x++;
            }
            while (A[y] > pivot) {
                y--;
            }
            if (x < y) {
                int temp = A[x];
                A[x] = A[y];
                A[y] = temp;
            }
        }
        A[l] = A[y];
        A[y] = pivot;
        return y;
    }
}
