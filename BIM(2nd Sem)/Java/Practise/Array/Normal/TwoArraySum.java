// WAP to calculate the sum and average of array elements

import java.util.Scanner;

public class TwoArraySum {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        // Take size of the array
        System.out.println("Enter the size of the array: ");
        int size=sc.nextInt();
        // Declare two arrays
        int []arr1=new int[size];
        int []arr2=new int[size];
        // Take input for 1st array
        System.out.println("Enter "+ size +" elements for 1st array: ");
        int sum=0;
        for(int i=0;i<size;i++){
            arr1[i]=sc.nextInt();
            sum+=arr1[i];
        }
        // Take input for 2nd array
        System.out.println("Enter "+ size +" elements for 2nd array: ");
        int arrSum[]=new int[5];
        for(int i=0;i<size;i++){
            arr2[i]=sc.nextInt();
            arrSum[i]=arr1[i]+arr2[i];
        }
        // Find average of 1st array
        double avg=(double)sum/size;
        // Display the sum of elements of both array
        System.out.println("Sum of elements of both array: ");
        for(int i=0;i<size;i++){
            System.out.println(arrSum[i]);
        }
        // Display average of 1st array
        System.out.println("Average of elements of array 1st: " + avg);
        sc.close();
    }
}

