/*
 *  Character Stream -> direct write or read character into file. It consist:
 *                    a.) File Writer : to write character into file
 *                    b.) File Reader : to read character from file
*/

import java.io.*;

public class CharacterStreamDemo{
   public static void main(String[]args){
       try{
           // Create new file
           File f1=new File("bim.txt");
           if(!f1.exists()){
               f1.createNewFile();
           }
           // Write to file using character stream
           String data= "Hi";
           FileWriter fw=new FileWriter(f1);
           fw.write(data); // Write into file
           fw.close();
           // Read from file using character stream
           FileReader fr=new FileReader(f1);
           int i;
           while((i=fr.read())!=-1){
               System.out.print((char)i);
           }
           fr.close();
       }
       catch(IOException i){
           System.out.println(i);
       }
   }
}