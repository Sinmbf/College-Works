// 3. Provide example on how constructor of super class is called.

// Super class
class Numbers {
    // Instance Variable
    private int n1;
    private int n2;

    // Constructor
    public Numbers(int n1, int n2) {
        this.n1 = n1;
        this.n2 = n2;
    }

    // Method to display
    public void displayNumber() {
        System.out.println("Number 1: " + n1 + "\nNumber 2: " + n2);
    }
}

// Child class
class Num extends Numbers {
    // Instance variable
    private int n3;

    // Constructor
    public Num(int n3, int n1, int n2) {
        super(n1, n2); // Call parent class constructor
        this.n3 = n3;
    }

    // Method to display number
    public void displayNum() {
        System.out.println("Number 3: " + n3);
    }
}

// Main class
public class Three {
    public static void main(String[] args) {
        // Create instance
        Num n1 = new Num(4, 5, 6);
        n1.displayNumber();
        n1.displayNum();
    }
}