class Rectangle<T extends Number,U extends Number>{
    private T length;
    private U breadth;
    public Rectangle(T length,U breadth){
        this.length=length;
        this.breadth=breadth;
    }
    public void calcArea(){
        System.out.println("Area of Rectangle is "+(length.intValue()*breadth.doubleValue()));
    }
}

public class GenericsDemo {
    public static void main(String[]args){
        Rectangle<Integer,Double>r1=new Rectangle<Integer,Double>(10,2.5);
        r1.calcArea();
    }
}
