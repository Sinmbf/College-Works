// WAP to create file and perform read and write operation using character stream.

/*

    Character stream: direct write or read character into file. It consists of:
        a.) FileWriter - to write character into file
        b.) FileReader - to read character from file

 */

import java.io.*;

public class Two {
    public static void main(String[] args) {
        try {
            // Create new file
            File f1 = new File("two.txt");
            if (!f1.exists()) {
                f1.createNewFile();
            }
            // Write into file using character stream
            String data = "Hello Sinmbf2";
            FileWriter fw = new FileWriter(f1);
            fw.write(data);
            System.out.println("Successfully written into file");
            fw.close();
            // Read data from file using character stream
            FileReader fr = new FileReader(f1);
            int i;
            System.out.println("Reading from file..." + "\nResult:");
            while ((i = fr.read()) != -1) {
                System.out.print((char) i);
            }
            fr.close();
        } catch (IOException e) {
            System.out.println("IOException: " + e);
        }
    }
}
