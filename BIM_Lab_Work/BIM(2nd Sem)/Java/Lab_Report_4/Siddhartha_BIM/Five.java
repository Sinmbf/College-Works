/* 

    Create a class Numbers with three integer instance variables x,y and z. The class will
    have one constructor to set the value of instance variable and method getMax() that find
    the greatest number between x,y and z and return the results. Create one object of Number
    and invoke the method to find greatest number.

*/

class Numbers {
    // Instance Variable
    private int x;
    private int y;
    private int z;

    // Constructor (Parameterized)
    public Numbers(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    // Method to find the greatest
    public int getMax() {
        return (x > y && x > z) ? x : (y > x && y > z) ? y : z;
    }
}

public class Five {
    public static void main(String[] args) {
        int x = 332;
        int y = 442;
        int z = 550;
        // create object
        Numbers n1 = new Numbers(x, y, z);
        // Call method
        int greatest = n1.getMax();
        // Display the greatest
        System.out.println("Largest among  " + x + ", " + y + " and " + z + ": " + greatest);
    }
}
