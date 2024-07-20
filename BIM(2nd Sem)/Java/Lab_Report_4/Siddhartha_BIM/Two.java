/*

    Create a class Calculate which contains data member num1 and num2 both in integer and 
    methods setCalc() to set the data, calcSum() that calculate the sum of num1 and num2 
    and display the result, calcMult() that calculate the multiplication of num1 and num2 
    and returns the result, calcDifference() that calculate the difference between num1 and
    num2 and display the result. Now, create some instance of Calculate and invoke all the 
    methods.

 */

class Calculate {
    // Member
    private int num1;
    private int num2;

    // Method to set value of member
    public void setCalc(int num1, int num2) {
        this.num1 = num1;
        this.num2 = num2;
    }

    // Method to calculate and display sum
    public void calcSum() {
        System.out.println(num1 + " + " + num2 + " = " + (this.num1 + this.num2));
    }

    // Method to calculate and return product
    public int calcMult() {
        return (this.num1 * this.num2);
    }

    // Method to calculate and display difference
    public void calcDifference() {
        System.out.println(num1 + " - " + num2 + " = " + (this.num1 - this.num2));
    }
}

public class Two {
    public static void main(String[] args) {
        // Create instance of class (object)
        Calculate c1 = new Calculate();
        Calculate c2 = new Calculate();
        // Method to set value of member
        c1.setCalc(3, 5);
        c2.setCalc(10, 20);
        // Method to add
        c1.calcSum();
        // Method to multiply
        int product = c2.calcMult();
        System.out.println("Product: " + product);
        // Method to subtract
        c2.calcDifference();
    }
}
