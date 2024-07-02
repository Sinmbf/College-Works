// WAP using switch case to print the day depending upon number inputted by user. (If input is 1 print Sunday, 2 then Monday and so on)

import java.util.Scanner;

public class Five {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Take input
        System.out.println("Enter a number: ");
        int choice = sc.nextInt();
        switch (choice) {
            case 1:
                System.out.println("Sunday");
                break;
            case 2:
                System.out.println("Monday");
                break;
            case 3:
                System.out.println("Tuesday");
                break;
            case 4:
                System.out.println("Wednesday");
                break;
            case 5:
                System.out.println("Thursday");
                break;
            case 6:
                System.out.println("Friday");
                break;
            case 7:
                System.out.println("Saturday");
                break;
            default:
                System.out.println("Invalid number");
        }
        sc.close();
    }
}
