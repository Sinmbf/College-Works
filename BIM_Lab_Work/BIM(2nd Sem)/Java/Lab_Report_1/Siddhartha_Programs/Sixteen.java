/* WAP using switch case for the following:

    a) First take one number input from user
    b) If 1 is pressed then again make user to input another value(BBA, BIM, BCA). After this, if BIM is chosen then print overall fee for BIM. Similarly, for others.
    c) If 2 is pressed then make user to input another value(BBM, BBS). If BBM is chosen then print overall fee for BBM. Similarly, for others.
*/

import java.util.Scanner;

public class Sixteen {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Take input
        System.out.print("Enter a number[1/2]: ");
        int choice = sc.nextInt();
        switch (choice) {
            case 1:
                System.out.print("Choose BBA, BIM, BCA: ");
                String course = sc.next();
                switch (course) {
                    case "BBA":
                        System.out.println("FEE for BBA: Rs 450000");
                        break;
                    case "BIM":
                        System.out.println("FEE for BIM: Rs 600000");
                        break;
                    case "BCA":
                        System.out.println("FEE for BCA: Rs 500000");
                        break;
                    default:
                        System.out.println("Course not available");
                }
                break;
            case 2:
                System.out.print("Choose BBM, BBS: ");
                course = sc.next();
                switch (course) {
                    case "BBM":
                        System.out.println("FEE for BBM: Rs 400000");
                        break;
                    case "BBS":
                        System.out.println("FEE for BBS: Rs 350000");
                        break;
                    default:
                        System.out.println("Course not available");
                }
                break;
            default:
                System.out.println("Invalid choice");
        }
        sc.close();
    }
}
