/*

    Create a class Rectangle with attributes length and breadth. The class contains method
    computeArea() and displayArea(). Now, create two object of Rectangle and find area and
    display the area.

*/

class Rectangle {
    // Member
    int length;
    int breadth;
    int area;

    // Method to compute area
    public void computeArea() {
        this.area = this.length * this.breadth;
    }

    // Method to display area
    public void displayArea() {
        System.out.println("Area of rectangle: " + this.area);
    }
}

public class Four {
    public static void main(String[] args) {
        // Create object
        Rectangle r1 = new Rectangle();
        // Set values of member
        r1.length = 5;
        r1.breadth = 10;
        // Call methods
        r1.computeArea();
        r1.displayArea();
    }
}
