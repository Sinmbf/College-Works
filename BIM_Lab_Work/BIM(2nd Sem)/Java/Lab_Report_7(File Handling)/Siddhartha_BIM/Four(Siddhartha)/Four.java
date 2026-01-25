// WAP that takes one line input from user and write to the file "first.txt". After this,
// copy the content of "first.txt" and paste it into "second.txt"

import java.io.*;
import java.util.Scanner;

public class Four {
    public static void main(String[] args) {
        // Create scanner object
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a line of text: ");
        String str = sc.nextLine();
        // Perform file operation
        try {
            // Open file for writing using character stream
            // If file doesn't exist, FileWriter and FileOutputStream will create it.
            // However, in case of FileReader and FileInputStream, it will show
            // FileNotFoundException
            FileWriter fw = new FileWriter("first.txt");
            fw.write(str);
            System.out.println("Successfully written into first.txt");
            fw.close();
            // Open file for reading using character stream and write content
            // into another file
            FileReader fr = new FileReader("first.txt");
            FileWriter fw2 = new FileWriter("second.txt");
            int i;
            while ((i = fr.read()) != -1) {
                fw2.write((char) i);
            }
            System.out.println("Successfully copied from first.txt into second.txt");
            fr.close();
            fw2.close();
            sc.close();
        } catch (IOException e) {
            System.out.println("IOException: " + e);
        }
    }
}
