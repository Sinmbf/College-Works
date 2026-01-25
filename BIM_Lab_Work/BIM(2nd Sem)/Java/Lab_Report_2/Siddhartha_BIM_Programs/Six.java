/* WAP that ask student to enter his/her marks for 5 subject and print the grade obtained
    
    a) 80-100 --> grade A
    b) 60-79 --> grade B
    c) 40-59 --> grade C
    d) Below 40 --> grade F

*/

import java.util.Scanner;

public class Six {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int subjects = 5;
        double totalMarks = 0;
        System.out.println("Enter marks in five subjects: ");
        for (int i = 0; i < 5; i++) {
            int mark = sc.nextInt();
            totalMarks += mark;
        }
        char grade = 'A';
        double average = totalMarks / subjects;
        if (average > 100) {
            System.out.println("Invalid");
        } else if (average >= 80 && average <= 100) {
            grade = 'A';
        } else if (average >= 60) {
            grade = 'B';
        } else if (average >= 40) {
            grade = 'C';
        } else {
            grade = 'F';
        }
        System.out.println("Grade: " + grade);
        sc.close();
    }
}
