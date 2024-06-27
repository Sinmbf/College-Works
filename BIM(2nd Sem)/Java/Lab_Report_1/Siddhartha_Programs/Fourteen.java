// WAP to read marks of five subjects and show percentage, total marks obtained and result (if obtained marks>35 pass otherwise fail)

import java.util.Scanner;

public class Fourteen {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean isPass = true;
        int[] marks = new int[5];
        int totalMarks = 0;
        for (int i = 0; i < 5; i++) {
            int next = i + 1;
            System.out.print("Enter marks of subject " + next + ": " + "\n");
            marks[i] = sc.nextInt();
            totalMarks += marks[i];
        }
        double percentage = (double) totalMarks / 500 * 100;
        System.out.println("Percentage: " + percentage + "\nTotal Marks Obtained: " + totalMarks);
        for (int mark : marks) {
            if (mark < 35) {
                System.out.println("Result: Fail");
                isPass = false;
                break;
            }
        }
        if (isPass) {
            System.out.println("Result: Pass");
        }
        sc.close();
    }
}
