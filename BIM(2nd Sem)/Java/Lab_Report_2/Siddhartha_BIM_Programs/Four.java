/* WAP to read marks of five subject, then find the division and percentage

    a) Percentage > = 80 --> Distinction
    b) Percentage > = 60 & < 80 --> First Division
    c) Percentage > = 40 & < 60 --> Second Division
    d) Percentage < 40 --> Fail

*/

import java.util.Scanner;

public class Four {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int totalMarks = 0;
        System.out.println("Enter marks in five subjects: ");
        for (int i = 0; i < 5; i++) {
            int mark = sc.nextInt();
            totalMarks += mark;
        }
        double percentage = (double) totalMarks / 500 * 100;
        System.out.println("Percentage: " + percentage);
        String division = " ";
        if (percentage >= 80 && percentage <= 100) {
            division = "Distinction";
        } else if (percentage >= 60) {
            division = "First Division";
        } else if (percentage >= 40) {
            division = "Second Division";
        } else {
            division = "Fail";
        }
        System.out.println("Division: " + division);
        sc.close();
    }
}
