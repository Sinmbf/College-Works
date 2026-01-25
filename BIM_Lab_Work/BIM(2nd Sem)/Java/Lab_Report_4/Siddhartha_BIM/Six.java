/* 

    Create a class Box with attributes length, breadth and height. The class contains method
    computeVolume() that computes the volume of box and return the volume. Now, create two
    object of box and find volume and display it

*/

class Box {
    // Instance Variable
    private int length;
    private int breadth;
    private int height;

    // Parameterized Constructor
    public Box(int length, int breadth, int height) {
        this.length = length;
        this.breadth = breadth;
        this.height = height;
    }

    // Method to compute volume
    public int computeVolume() {
        return this.length * this.breadth * this.height;
    }
}

public class Six {
    public static void main(String[] args) {
        // Create object
        Box b1 = new Box(10, 20, 30);
        Box b2 = new Box(40, 50, 60);
        // Call method to find volume
        int volume1 = b1.computeVolume();
        int volume2 = b2.computeVolume();
        // Display volume
        System.out.println("Volume of box 1: " + volume1);
        System.out.println("Volume of box 2: " + volume2);
    }
}
