/* WAP to read annual salary of an employee and calculate the tax and print the actual amount received by the employee
    
    a) Salary upto 100000 -> 1%
    b) Salary above 100000 and below 500000 -> 5%
    c) Salary above 500000 -> 10%

*/

import java.util.Scanner;

public class Eight {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter annual salary: ");
        int salary = sc.nextInt();
        double tax = 0;
        if (salary > 500000) {
            tax = 0.1 * salary;
        } else if (salary > 100000) {
            tax = 0.05 * salary;
        } else {
            tax = 0.01 * salary;
        }
        double actualSalary = salary - tax;
        System.out.println("Actual salary: " + actualSalary);
        sc.close();
    }
}
