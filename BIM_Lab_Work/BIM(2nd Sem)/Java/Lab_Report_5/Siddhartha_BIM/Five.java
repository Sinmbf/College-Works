// 5. Create an abstract class FMachine having methods getData() and putData().
// Derive a class Airplane having instance variable code, name, capacity and
// methods getData() and putData() that overrides method of abstract class to
// read and display the result. Create some instances of Airplane and call the
// required methods.

// Abstract class
abstract class FMachine {
    // Methods
    abstract void getData(int code, String name, int capacity);

    abstract void putData();
}

// Sub class (Child of abstract class)
class Airplane extends FMachine {
    // Instance variable
    private int code;
    private String name;
    private int capacity;

    // Parent class method
    // Method to set data
    public void getData(int code, String name, int capacity) {
        this.code = code;
        this.name = name;
        this.capacity = capacity;
    }

    // Method to display data
    public void putData() {
        System.out.println("Code: " + this.code + "\nName: " + this.name + "\nCapacity: " + this.capacity);
    }
}

// Main Class
public class Five {
    public static void main(String[] args) {
        // Create object
        Airplane a1 = new Airplane();
        Airplane a2 = new Airplane();
        // Call Method to set data
        a1.getData(101, "Fighter", 100);
        a2.getData(102, "Jet", 95);
        // Display details
        System.out.println("Details of airplane 1: ");
        a1.putData();
        System.out.println("Details of airplane 2: ");
        a2.putData();
    }
}