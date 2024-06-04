import java.util.Scanner;
public class prime2 {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter two numbers: ");
        int n1=sc.nextInt();
        int n2=sc.nextInt();
        if(n1>n2){
            int temp=n1;
            n1=n2;
            n2=temp;
        }
        System.out.println("Prime numbers from "+ n1+" to "+ n2);
        for(int i=n1;i<=n2;i++){
            int flag=1;
            for(int j=2;j<i;j++){
                if(i%j==0){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                System.out.println(i);
            }
        }
    }
}
