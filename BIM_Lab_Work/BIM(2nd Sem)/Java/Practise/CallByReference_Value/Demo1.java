class Rectangle{
    // Instance Variable
    private int length;
    private int breadth;
    // Constructor
    public Rectangle(int length,int breadth){
        this.length=length;
        this.breadth=breadth;
    }
    // Method to compare rectangle
    public void compareRectangle(Rectangle r){
        if(this.length==r.length && this.breadth==r.breadth){
            System.out.println("Both are equal");
        }
        else{
            System.out.println("Both are not equal");
        }
    }                                                                                                                                                                                                               
}

public class Demo1{
    public static void main(String[]args){
        // Create Object
        Rectangle r1=new Rectangle(3,5);
        Rectangle r2=new Rectangle(4,5);
        r1.compareRectangle(r2);
    }
}