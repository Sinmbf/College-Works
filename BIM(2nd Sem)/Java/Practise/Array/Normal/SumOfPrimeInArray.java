import java.util.Scanner;

public class SumOfPrimeInArray {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        // Take input
        System.out.println("Enter the size of the array: ");
        int size=sc.nextInt();
        System.out.println("Enter " + size + " elements: ");
        // Declare array
        int []arr=new int[size];
        // Take input in array
        for(int i=0;i<size;i++){
            arr[i]=sc.nextInt();
        }
        // Find the sum of prime numbers in array
        int sumOfPrime=0;
        for(int i=0;i<size;i++){
            boolean isPrime=true;
            for(int j=2;j<arr[i];j++){
                if(arr[i]%j==0){
                    isPrime=false;
                    // break;
                } 
            }
            if(isPrime && arr[i]!=1){
                sumOfPrime+=arr[i];
            }
        }
        // Display the sum
        System.out.println("Sum of prime numbers in the array: " + sumOfPrime);
        sc.close();
    }
}
