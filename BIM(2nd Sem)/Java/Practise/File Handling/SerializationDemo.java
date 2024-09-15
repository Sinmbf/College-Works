import java.io.*;

class Movie implements Serializable {
    int ID;
    String genre;
    
    public void setMovie(int ID, String genre) {
        this.ID = ID;
        this.genre = genre;
    }
    
    public void displayMovie() {
        System.out.println(this.ID);
        System.out.println(this.genre);
    }
}

public class SerializationDemo {
    public static void main(String[] args) {
        Movie m1 = new Movie();
        m1.setMovie(101, "Comedy"); // Ensure this matches the check in the deserialization program
        
        try {
            File file = new File("comedy.dat");
            FileOutputStream fos = new FileOutputStream(file);
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            
            // Write object to file
            oos.writeObject(m1);
            
            oos.close();
            fos.close();
        } catch (IOException e) {
            System.out.println("IOException: " + e);
        }
    }
}
