/* 

    Create a class Number having instance variable  x and y both in integer, default
    constructor that set the value of x and y to 0, parameterized constructor that sets 
    the value of x and y, method findOdd() that calculates the odd no. occurring between
    x and y and display the result, findEven() that calculates the even no. occurring 
    between x and y and display the results. Now, create some instance of Number and invoke
    all the methods

*/

import java.util.Scanner;

class Number {
    // Instance variable
    private int x;
    private int y;

    // Default Constructor
    public Number() {
        this.x = 0;
        this.y = 0;
        System.out.println("Instance variable set to 0");
    }

    // Parameterized Constructor
    public Number(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // Method to find odd between x and y
    public void findOdd() {
        System.out.println("Odd numbers from " + this.x + " to " + this.y);
        for (int i = this.x; i <= this.y; i++) {
            if (i % 2 != 0) {
                System.out.print(i + "\t");
            }
        }
    }

    // Method to find even between x and y
    public void findEven() {
        System.out.println("\nEven numbers from " + this.x + " to " + this.y);
        for (int i = this.x; i <= this.y; i++) {
            if (i % 2 == 0) {
                System.out.print(+i + "\t");
            }
        }
    }
}

public class Three {
    public static void main(String[] args) {
        // create object
        Scanner sc = new Scanner(System.in);
        // Create instance of Number(object)
        // Default Constructor
        Number n1 = new Number();
        // Take input two numbers
        System.out.println("Enter two numbers: ");
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        // Parameterized Constructor
        Number n3 = new Number(num1, num2);
        if (num2 > num1) {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        // Call methods
        n3.findOdd();
        n3.findEven();
        sc.close();
    }
}
