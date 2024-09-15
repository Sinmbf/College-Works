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

public class DeserializationDemo {
    public static void main(String[] args) {
        try {
            File file = new File("comedy.dat");
            if (file.exists() && file.length() > 0) {
                FileInputStream fis = new FileInputStream(file);
                ObjectInputStream ois = new ObjectInputStream(fis);
                
                // Read object from file
                Movie m1 = (Movie) ois.readObject();
                
                ois.close();
                fis.close();
                
                // Display the movie
                m1.displayMovie();
            } else {
                System.out.println("File does not exist or is empty.");
            }
        } catch (IOException e) {
            System.out.println("IOException: " + e);
        } catch (ClassNotFoundException e) {
            System.out.println("ClassNotFoundException: " + e);
        }
    }
}
