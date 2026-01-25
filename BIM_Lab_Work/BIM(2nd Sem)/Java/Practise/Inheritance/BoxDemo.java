class Box{
    int length;
    int breadth;
    int height;
    // Methods to set instance variable
    public void setBox(int length,int breadth,int height){
        this.length=length;
        this.breadth=breadth;
        this.height=height;
    }
    // Method to compute volume
    public int calculateVolume(){
        return (this.length*this.breadth*this.height);
    }
}

// Creating child class
class BoxWeight extends Box{
    int weight;
    // Methods to set weight
    public void setWeight(int weight){
        this.weight=weight;
    }
    // Methods to display weight
    public void displayWeight(){
        System.out.println("Weight of box: " + this.weight);
    }
}
public class BoxDemo {
    public static void main(String[]args){
        // Create object of child class
        BoxWeight bw1=new BoxWeight();
        BoxWeight bw2=new BoxWeight();
        // Use method of parent
        bw1.setBox(3, 4, 5);
        bw2.setBox(6, 7, 8);
        int volume1=bw1.calculateVolume();
        int volume2=bw2.calculateVolume();
        // Use own method
        bw1.setWeight(20);
        bw2.setWeight(40);        
        // Display the detals of both box
        System.out.println("Details of box 1: ");
        System.out.println("Volume: " + volume1 + "\nWeight: " + bw1.weight);
        System.out.println("Details of box 2: ");
        System.out.println("Volume: " + volume2 + "\nWeight: " + bw2.weight);
    } 
}
