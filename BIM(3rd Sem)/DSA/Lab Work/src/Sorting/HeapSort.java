package Sorting;

import java.util.Scanner;

public class HeapSort {

    static int A[] = new int[100];
    static int n, n1;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array ????");
        n = sc.nextInt();
        n1 = n;

        System.out.println("Enter Elements of araay ????");

        for (int i = 1; i <= n; i++) {
            System.out.println("A[" + i + "] : ");
            A[i] = sc.nextInt();
        }

        System.out.println("DATA BEFORE SORTING: ");
        System.out.println("*********************");
        display();

        heapSort();

        System.out.println("\nDATA AFTER SORTING: ");
        System.out.println("*********************");
        display();
    }

    public static void heapSort() {
        MAX_HEAP_BUILD();
        for (int i = n1; i >= 2; i--) {
            int temp = A[1];
            A[1] = A[n1];
            A[n1] = temp;
            n1--;
            Heapify(1);

        }

    }

    public static void display() {
        for (int i = 1; i <= n; i++) {
            System.out.print(A[i] + "\t");
        }
    }

    private static void MAX_HEAP_BUILD() {
        for (int i = n1 / 2; i >= 1; i--) {
            Heapify(i);

        }
    }

    private static void Heapify(int i) {
        int l = 2 * i;
        int r = 2 * i + 1;
        int largest = i;
        if (l <= n1 && A[l] > A[largest]) {
            largest = l;
        }
        if (r <= n1 && A[r] > A[largest]) {
            largest = r;
        }
        if (i != largest) {
            int temp = A[i];
            A[i] = A[largest];
            A[largest] = temp;
            Heapify(largest);
        }
    }

}
