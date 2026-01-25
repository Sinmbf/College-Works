// 5.	Provide example on dynamic method dispatch

// Dynamic method dispatch =>  Object of subclass is assigned to reference variable of
//                             parent class then such reference will call subclass version
//                             of overridden method

// Dynamic method dispatch in Java is a mechanism by which a call to an overridden method is resolved at runtime rather than at compile-time. This is a key feature of Java's runtime polymorphism, allowing a method to be overridden in subclasses and enabling Java to determine the appropriate method to invoke based on the actual object type, not the reference type.

// Parent Class
class Calculation {
    // Method to calculate sum
    public void calc(int x, int y) {
        System.out.println("Method of parent: ");
        System.out.println(x + " + " + y + ": " + (x + y));
    }
}

// Child class
class Calculate extends Calculation {
    // The @Override keyword in Java is an annotation that you use to indicate that
    // a method is intended to override a method in a superclass.

    // It ensures that the method is actually overriding a method in the superclass.
    // If
    // the method does not match any method in the superclass, the compiler will
    // generate an error.

    // Method to calculate difference
    @Override
    public void calc(int x, int y) {
        System.out.println("method (sub class): ");
        System.out.println(x + " - " + y + ": " + (x - y));
    }
}

// Main Class
public class Five {
    public static void main(String[] args) {
        // Create object of child class
        Calculate c = new Calculate();
        // Assign object of sub class to reference variable of parent
        Calculation c1 = c;
        // Call method of parent(It will refer to method of child)
        c1.calc(5, 10);

    }
}
