// WAP to demonstrate switch case statement and nested switch case statement

import java.util.Scanner;

public class Fifteen {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("*****RESTAURANT MENU*****");
        System.out.println("1. MOMO\n2. CHOWMEIN");
        // Take user choice as input
        System.out.print("What do you want to order?[1-2]: ");
        int choice = sc.nextInt();
        switch (choice) {
            case 1:
                System.out.println("*****MOMO VARIETIES*****");
                System.out.println("1. Buff Momo --> Rs 120\n2. Chicken Momo --> Rs 130");
                System.out.print("What do you want to order?[1-2]: ");
                choice = sc.nextInt();
                switch (choice) {
                    case 1:
                        System.out.println("You ordered buff momo");
                        break;
                    case 2:
                        System.out.println("You ordered chicken momo");
                        break;
                    default:
                        System.out.println("Not available");
                }
                break;
            case 2:
                System.out.println("*****CHOWMEIN VARIETIES*****");
                System.out.println("1. Buff Chowmein --> Rs 120\n2. Chicken Chowmein --> Rs 130");
                System.out.print("What do you want to order?[1-2]: ");
                choice = sc.nextInt();
                switch (choice) {
                    case 1:
                        System.out.println("You ordered buff chowmein");
                        break;
                    case 2:
                        System.out.println("You ordered chicken chowmein");
                        break;
                    default:
                        System.out.println("Not available");
                }
                break;
            default:
                System.out.println("Not available");
        }
        sc.close();
    }
}
