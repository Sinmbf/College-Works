class Rectangle{
    // Instance Variable
    private int length;
    private int breadth;
    // Parameterized Constructor
    public Rectangle(int length,int breadth){
        this.length=length;
        this.breadth=breadth;
    }
    // Method to get length
    public int getLength(){
        return this.length;
    }
    // Method to get breadth
    public int getBreadth(){
        return this.breadth;
    }
    // Method to swap length and breadth
    public void swap(Rectangle r){
        int temp=r.length;
        r.length=r.breadth;
        r.breadth=temp;
    }                                                                                                                                                                                                               
}

public class Demo2{
    public static void main(String[]args){
        // Create Object
        Rectangle r1=new Rectangle(3,5);
        int length=r1.getLength();
        int breadth=r1.getBreadth();
        // Before Swap
        System.out.println("Before swap: " + "\nLength: " + length + "\nBreadth: " + breadth);
        r1.swap(r1);
        length=r1.getLength();
        breadth=r1.getBreadth();
        // After Swap
        System.out.println("After swap: " + "\nLength: " + length + "\nBreadth: " + breadth);
    }
}