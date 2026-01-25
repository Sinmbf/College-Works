// Explain abstract class with example

abstract class Calculation{
    // Instance Variable
    private int x;
    private int y;
    // Constructor
    public Calculation(int x, int y){
        this.x=x;
        this.y=y;
    }
    // Normal method
    public void calcSum2(){
        System.out.println("Sum: " + (x+y));
    }
    // Abstract method
    abstract void calcSum(int x,int y);
    abstract int calcMul(int x,int y);
}

class Calculate extends Calculation{
    private int z;
    public Calculate(int z,int x,int y){
        super(x,y);
        this.z=z;
    }
    // Abstract class methods implementation
    public void calcSum(int x,int y){
        System.out.println(x+" + " + y+": " + (x+y));
    }
    public int calcMul(int x,int y){
        return (x*y);
    }
}

public class AbstractClassDemo{
    public static void main(String[]args){
        // Create instance
        Calculate c1=new Calculate(1,2,3);
        // Call methods of parent
        c1.calcSum(10,20);
        c1.calcSum2();
        int product=c1.calcMul(30,40);
        System.out.println("Product: " + product);
    }
}