// WAP to create file and perform read and write operation using byte stream

/*

    Byte stream: convert all the character into byte. It consists of:
        a.) FileInputStream - to read data from file as byte
        b.) FileOutputStream - to write byte into file

 */

import java.io.*;

public class One {
    public static void main(String[] args) {
        try {
            // Create new file
            File f1 = new File("example.txt");
            if (!f1.exists()) {
                f1.createNewFile();
            }
            // Write to file using byte stream
            String data = "Hello Sinmbf";
            FileOutputStream fos = new FileOutputStream(f1);
            // Convert string into byte
            byte[] b1 = data.getBytes();
            fos.write(b1);
            System.out.println("Successfully written into file");
            fos.close();
            // Read from file using byte stream
            FileInputStream fis = new FileInputStream(f1);
            int i;
            System.out.println("Reading from file..." + "\nResult:");
            while ((i = fis.read()) != -1) {
                // fis.read() returns an int representing the next byte of data from file
                // If end of file(EOF) is reached then it returns -1`
                System.out.print((char) i);
            }
            fis.close();
        } catch (IOException e) {
            System.out.println("IO Exception: " + e);
        }
    }
}