// 4.	Provide example on method overriding condition

// Parent class
class Calculation {
    // Method to set calculate
    public void calc(int x, int y) {
        System.out.println("Method of parent: ");
        System.out.println(x + " + " + y + ": " + (x + y));
    }
}

// Child Class
class Calculate extends Calculation {
    // Method to calculate
    public void calc(int x, int y) {
        super.calc(x, y); // Call parent method
        System.out.println("Own method: ");
        System.out.println(x + " - " + y + ": " + (x - y));
    }
}

// Main class
public class Four {
    public static void main(String[] args) {
        // Create object
        Calculate c = new Calculate();
        // Call methods
        c.calc(10, 5);
    }
}
