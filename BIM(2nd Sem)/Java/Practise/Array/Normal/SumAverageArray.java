// WAP to calculate the sum and average of array elements

import java.util.Scanner;

public class SumAverageArray {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array: ");
        int size=sc.nextInt();
        int []arr=new int[size];
        System.out.println("Enter "+ size +" elements: ");
        int sum=0;
        for(int i=0;i<size;i++){
            arr[i]=sc.nextInt();
            sum+=arr[i];
        }
        double avg=(double)sum/size;
        System.out.println("Sum of elements: " + sum + "\nAverage: " + avg);
        sc.close();
    }
}
