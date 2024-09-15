import java.util.Scanner;

public class SumOfOddInArray {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        // Take input
        System.out.println("Enter the size of the array: ");
        int size=sc.nextInt();
        System.out.println("Enter " + size + " elements: ");
        // Declare array
        int []arr=new int[size];
        // Take input in array
        int sumOfOdd=0;
        for(int i=0;i<size;i++){
            arr[i]=sc.nextInt();
            // Find sum of odd integers in array
            if(arr[i]%2!=0){
                sumOfOdd+=arr[i];
            }
        }
        // Display the sum
        System.out.println("Sum of odd integers in the array: " + sumOfOdd);
        sc.close();
    }
}
