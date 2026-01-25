class FirstClass{
    // Instance variable
    int a;
    int b;
}

public class InstanceVariableDemo {
    public static void main(String[]args){
        FirstClass fc=new FirstClass();
        fc.a=10;
        fc.b=20;
        System.out.println("Product: "+ (fc.a*fc.b));
    }
}
