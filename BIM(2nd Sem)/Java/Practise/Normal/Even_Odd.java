import java.util.Scanner;

public class Even_Odd {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        // Take input
        System.out.println("Enter 1st number: ");
        int n1=sc.nextInt();
        System.out.println("Enter 2nd number: ");
        int n2=sc.nextInt();
        if(n1>n2){
            int temp=n1;
            n1=n2;
            n2=temp;
        }
        System.out.println("Even numbers from " + n1 +" to " + n2 + ": ");
        for(int i=n1;i<=n2;i++){
            if(i%5==0){
                continue;
            }
            if(i%2==0)
            System.out.println(i);  
        }
    }
}
