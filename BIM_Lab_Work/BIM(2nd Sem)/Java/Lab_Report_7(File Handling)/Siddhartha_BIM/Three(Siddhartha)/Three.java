// WAP to perform serialization and deserialization in java.

/*
    
    Serialization - process of writing object into file
    Deserialization - process of reading object from file

    To write -> ObjectOutputStream
    To read -> ObjectInputStream

    To use serialization, a class has to implement serializable interface

 */

import java.io.*;

// Serializable class
class Rectangle implements Serializable {
    // Instance variable
    private int length;
    private int breadth;

    // Methods
    public void setRectangle(int length, int breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public void calcArea() {
        System.out.println("Area of rectangle: " + (this.length * this.breadth));
    }
}

public class Three {
    public static void main(String[] args) {
        // Create object
        Rectangle r1 = new Rectangle();
        r1.setRectangle(10, 20);
        // Perform file operation
        try {
            // Create file
            File f1 = new File("Three.txt");
            if (!f1.exists()) {
                f1.createNewFile();
            }
            // Open file for writing object (Serialization)
            FileOutputStream fos = new FileOutputStream(f1);
            ObjectOutputStream os = new ObjectOutputStream(fos);
            // Write into file
            os.writeObject(r1);
            System.out.println("Successfully written object into file");
            os.close();
            // Open file for reading object (Deserialization)
            FileInputStream fis = new FileInputStream(f1);
            ObjectInputStream ois = new ObjectInputStream(fis);
            // The compiler cannot automatically know which class it is when deserializing
            // it. That's why you must explicitly cast it to the correct class, ensuring
            // that the type you expect matches the actual type of the deserialized object.

            // Read from file
            Rectangle r2 = (Rectangle) ois.readObject();
            System.out.println("Reading object from file..." + "\nUse method of the object:");
            r2.calcArea();
            fis.close();
            ois.close();
        } catch (IOException e) {
            // Thrown if an I/O error occurs during reading.
            System.out.println("IOException: " + e);
        } catch (ClassNotFoundException ce) {
            // ClassNotFoundException: Thrown if the class of the serialized object cannot
            // be found.
            System.out.println("ClassNotFoundException: " + ce);
        }
    }
}
