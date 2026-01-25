// WAP to read marks of five subjects and show percentage, total marks obtained and result (if obtained marks>35 pass otherwise fail)

import java.util.Scanner;

public class Fourteen {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean isPass = true;
        int totalMarks = 0;
        for (int i = 1; i <= 5; i++) {

            System.out.print("Enter marks of subject " + i + ": ");
            int marks = sc.nextInt();
            if (marks <= 35) {
                isPass = false;
            }
            totalMarks += marks;
        }
        double percentage = (double) totalMarks / 500 * 100;
        System.out.println("Percentage: " + percentage + "\nTotal Marks Obtained: " + totalMarks);
        if (isPass) {
            System.out.println("Result: Pass");
        } else {
            System.out.println("Result: Fail");
        }
        sc.close();
    }
}
