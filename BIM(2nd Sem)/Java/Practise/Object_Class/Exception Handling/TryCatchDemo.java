// Example of exception handling

import java.util.Scanner;

public class TryCatchDemo {
    public static void main(String[]args){
        // Create object
        Scanner sc=new Scanner(System.in);
        // Take input
        System.out.println("Enter two numbers: ");
        int n1=sc.nextInt();
        int n2=sc.nextInt();
        // Try catch block
        try{
            int division= n1/n2; // if n2=0, error occur (Arithmetic Exception)
            System.out.println("Division: " + division);
            // Array Exception
            int []arr1=new int[5];
            for(int i=0;i<=5;i++){
                arr1[i]=i; // More than 5 elements so error
            }
        }
        catch(ArithmeticException err){
            System.out.println("Cannot divide by 0\n" + err);
        }
        catch(ArrayIndexOutOfBoundsException err){
            System.out.println("Size exceeded by the array\n" + err);
        }
        // Main error
        catch(Exception err){
            System.out.println(err);
        }
        // Finally block
        finally{
            System.out.println("This is finally block");
        }
        System.out.println("Out of catch block");
        sc.close();
    }
}
