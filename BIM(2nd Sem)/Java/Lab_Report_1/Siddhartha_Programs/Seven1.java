// WAP to demonstrate all conditional statement (if, if...else, if...else if...else) and loops (while, do...while, for and for each loop)

public class Seven1 {
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
        i = 0;
        int countEligible = 0;
        int countNotEligible = 0;
        do {
            if (personAge[i] <= 0) {
                System.out.println("Found invalid age");
                i++;
                continue;
            } else if (personAge[i] >= 18) {
                countEligible++;
            } else {
                countNotEligible++;
            }
            i++;
        } while (i < 4);
        System.out.println(
                "Person eligible to vote: " + countEligible + "\nPerson not eligible to vote: " + countNotEligible);

    }
}
