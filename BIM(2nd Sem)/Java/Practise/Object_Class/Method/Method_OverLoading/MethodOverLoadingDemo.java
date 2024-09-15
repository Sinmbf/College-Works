package Method_OverLoading;

class Calculate{
    // Method Overloading
    public int sum(int n1,int n2){
        return (n1+n2);
    }
    public double sum(double n1,double n2){
        return (n1+n2);
    }
}


public class MethodOverLoadingDemo {
    public static void main(String[]args){
        // Create object
        Calculate c1=new Calculate();
        // Call method
        int sumOfTwo=c1.sum(2,3);
        double sumOfThree=c1.sum(4.5,6.3);
        System.out.println("Sum of two numbers: " + sumOfTwo);
        System.out.println("Sum of three numbers: " + sumOfThree);
    }
}
