/*
 *  Byte Stream -> convert all the character into byte. It consist:
 *                    a.) File Input Stream : to read data from file as byte
 *                    b.) File Output Stream : to write byte into file
*/

 import java.io.*;

 public class ByteStreamDemo{
    public static void main(String[]args){
        try{
            // Create new file
            File f1=new File("bim.txt");
            if(!f1.exists()){
                f1.createNewFile();
            }
            // Write to file using byte stream
            String data= "Hello";
            FileOutputStream fos=new FileOutputStream(f1);
            byte []b1=data.getBytes(); // Change into byte
            fos.write(b1);  // write into file
            fos.close();
            // Read from file using byte stream
            FileInputStream fis=new FileInputStream(f1);
            int i;
            while((i=fis.read())!=-1){
                System.out.print((char)i);
            }
            fis.close();
        }
        catch(IOException i){
            System.out.println(i);
        }
    }
 }