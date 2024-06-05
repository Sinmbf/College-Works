import java.util.Scanner;
public class prime2 {
    public static void main(String[]args){
        // Create Scanner object
        Scanner sc=new Scanner(System.in);
        // Take input
        System.out.println("Enter two numbers: ");
        int n1=sc.nextInt();
        int n2=sc.nextInt();
        // If n1>n2 then swap
        if(n1>n2){
            int temp=n1;
            n1=n2;
            n2=temp;
        }
        // Display the prime numbers
        System.out.println("Prime numbers from "+ n1+" to "+ n2);
        for(int i=n1;i<=n2;i++){
            int flag=1;
            for(int j=2;j<i;j++){
                // Not prime
                if(i%j==0){
                    flag=0;
                    break;
                }
            }
            // Prime
            if(flag==1){
                System.out.println(i);
            }
        }
    }
}
