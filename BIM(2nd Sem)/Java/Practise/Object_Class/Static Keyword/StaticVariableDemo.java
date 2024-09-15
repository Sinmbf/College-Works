class StaticBox{
    int length; // normal
    // Static variable
    static int breadth; 
    static int height; 
    // Static method
    public static void setData(int breadth,int height){
        // Length can't be read by static method
        // can't be accessed using 'this' keyword
        StaticBox.breadth=breadth;
        StaticBox.height=height;
    }
    public static void displayData(){
        System.out.println("breadth: " + breadth);
        System.out.println("height: " + height);
    }
    // Static Block
    static{
        height=5*breadth;
    }
}

public class StaticVariableDemo {
    public static void main(String[]args){
        StaticBox r1=new StaticBox();
        r1.length=10;
        // r1.breadth=20; // can't be accessed like this as it is a static variable
        StaticBox.breadth=20; // can only be accessed by using class name
        StaticBox.setData(20,30);
        int area=r1.length*StaticBox.breadth*StaticBox.height;
        System.out.println("Area of box: " + area);
        // Display
        StaticBox.displayData();
    }
}
