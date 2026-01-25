import java.util.Scanner;

public class Palindrome {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        // Take input
        System.out.println("Enter a number: ");
        int n=sc.nextInt();
        int originalNum=n;
        int rev=0;
        while(n!=0){
            rev=rev*10+n%10;
            n/=10;
        }
        if(originalNum==rev){
            System.out.println(originalNum + " is palindrome");
        }
        else{
            System.out.println(originalNum + " is not palindrome");
        }
        sc.close();
    }
}
