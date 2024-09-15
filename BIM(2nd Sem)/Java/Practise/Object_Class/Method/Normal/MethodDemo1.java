class Rectangle{
    public int FindArea(int l,int b){
        return (l*b);
    }
}

public class MethodDemo1 {
    public static void main(String[]args){
        Rectangle r1=new Rectangle();
        Rectangle r2=new Rectangle();
        // Call Method
        int area1=r1.FindArea(10,20);
        int area2=r2.FindArea(20,30);
        System.out.println("Area 1: " + area1);
        System.out.println("Area 2: " + area2);
    }
}
