import java.util.Scanner;

public class TwinPrime1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers: ");
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        int large = (n1 > n2) ? n1 : n2;
        int count = 0;
        for (int i = 1; i <= large; i++) {
            if (i == 1) {
                count += 2;
                continue;
            }
            if (n1 % i == 0 || n2 % i == 0) {
                count++;
            }
        }
        if (count != 4) {
            System.out.println("One of the numbers is not prime");
        } else {
            int diff = (n1 > n2) ? (n1 - n2) : (n2 - n1);
            if (diff == 2) {
                System.out.println("Twin Prime");
            } else {
                System.out.println("Not Twin Prime");
            }
        }
        sc.close();
    }
}