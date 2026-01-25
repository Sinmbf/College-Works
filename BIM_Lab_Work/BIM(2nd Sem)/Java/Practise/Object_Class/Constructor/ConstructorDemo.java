class Rectangle{
    // Instance Variable
    private int length;
    private int breadth;
    // Default Constructor
    public Rectangle(){
        System.out.println("This is rectangle");
    }
    // Parameterized Constructor
    public Rectangle(int l,int b){
        this.length=l;
        this.breadth=b;
    }
    // Method to find area of rectangle
    public int Area(){
        return (this.length*this.breadth);
    }

}

public class ConstructorDemo {
    public static void main(String[]args){
        // Default Constructor
        Rectangle r1=new Rectangle();
        // Parameterized Constructor
        Rectangle r2=new Rectangle(8,9);
        int area=r2.Area();
        System.out.println("Area of rectangle 2: "+ area);
    }
}
