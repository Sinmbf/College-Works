import java.util.Scanner;

public class TwinPrime {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter two numbers: ");
        int n1=sc.nextInt();
        int n2=sc.nextInt();
        // Check if prime
        boolean isPrime=true;
        for(int i=2;i<n1;i++){
            if(n1%i==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime && n1!=1){
            for(int i=2;i<n2;i++){
                if(n2%i==0){
                    isPrime=false;
                    break;
                }
            }
            if(isPrime && n2!=1){
                int diff=(n1>n2)?(n1-n2):(n2-n1);
                if(diff==2){
                    System.out.println("Twin prime");
                }
                else{
                    System.out.println("Not twin prime");
                }
            }
            else{
                System.out.println("One of the number is not prime");
            }
        }
        else{
            System.out.println("One of the number is not prime");
        }
        
    }
}
