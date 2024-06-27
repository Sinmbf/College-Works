// WAP to demonstrate all conditional statement (if, if...else, if...else if...else) and loops (while, do...while, for and for each loop)

public class Seven {
    public static void main(String[] args) {
        int[] personAge = { 0, 10, 11, 23, 18 };
        int countInvalid = 0;
        int countEligible = 0;
        int countNotEligible = 0;
        // For each loop with if condition
        for (int age : personAge) {
            if (age <= 0) {
                countInvalid++;
            }
        }
        // For loop
        for (int i = 0; i < 5; i++) {
            if (personAge[i] >= 18) {
                countEligible++;
            } else {
                countNotEligible++;
            }
        }
        countEligible = 0;
        countNotEligible = 0;
        countInvalid = 0;
        // while Loop
        int i = 0;
        while (i < 5) {
            if (personAge[i] <= 0) {
                countInvalid++;
            } else if (personAge[i] >= 18) {
                countEligible++;
            } else {
                countNotEligible++;
            }
            i++;
        }
        i = 0;
        countEligible = 0;
        countNotEligible = 0;
        countInvalid = 0;
        // do...while Loop
        do {
            if (personAge[i] <= 0) {
                countInvalid++;
            } else if (personAge[i] >= 18) {
                countEligible++;
            } else {
                countNotEligible++;
            }
            i++;
        } while (i < 5);
        System.out.println("Number of invalid age: " + countInvalid);
        System.out.println("Number of person eligible to vote: " + countEligible);
        System.out.println("Number of person not eligible to vote: " + countNotEligible);
    }
}
