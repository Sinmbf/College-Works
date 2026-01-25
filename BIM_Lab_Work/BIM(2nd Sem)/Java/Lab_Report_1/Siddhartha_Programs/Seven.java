// WAP to demonstrate all conditional statement (if, if...else, if...else if...else) and loops (while, do...while, for and for each loop)

public class Seven {
    public static void main(String[] args) {
        int[] personAge = { 0, 12, 18, 19 };
        int countInvalid = 0;
        // For...each loop
        for (int age : personAge) {
            if (age <= 0) {
                countInvalid++;
            }
        }
        System.out.println("Number of invalid age: " + countInvalid);
        // For loop
        System.out.println("Even Numbers from 1-10:");
        for (int i = 1; i <= 10; i++) {
            if (i % 2 == 0) {
                System.out.println(i);
            }
        }
        // While loop
        int even = 0;
        int odd = 0;
        int i = 1;
        System.out.println("From 1-10:");
        while (i <= 10) {
            if (i % 2 == 0) {
                even++;
            } else {
                odd++;
            }
            i++;
        }
        System.out.println("Even numbers count: " + even + "\nOdd numbers count: " + odd);
        // do...while Loop
        i = 1;
        do {
            if (i == 1) {
                System.out.println("Sunday");
            } else if (i == 2) {
                System.out.println("Monday");
            } else {
                System.out.println("Tuesday");
            }
            i++;
        } while (i <= 3);

    }
}
