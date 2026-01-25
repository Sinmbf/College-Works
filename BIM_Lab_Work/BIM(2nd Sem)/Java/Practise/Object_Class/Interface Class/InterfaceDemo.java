// Explain Interface with Dynamic method dispatch

interface Calcs1{
    void calcSum(int x,int y);
    void calcDifference(int x,int y);
}

interface Calcs2{
    void calcProduct(int x,int y);
}

// Multiple inheritance condition
class Solution implements Calcs1,Calcs2{
    @Override
    public void calcSum(int x,int y){
        System.out.println("Sum: " + (x+y));
    }
    @Override
    public void calcDifference(int x,int y){
        System.out.println("Difference: " + (x-y));
    }
    @Override
    public void calcProduct(int x,int y){
        System.out.println("Product: " + (x*y));
    }
}


public class InterfaceDemo{
    public static void main(String[]args){
        Solution s1=new Solution();
        // Dynamic Method Dispatch
        Calcs1 c1=s1; // Object of sub class is assigned to reference variable of parent
        Calcs2 c2=s1; // Object of sub class is assigned to reference variable of parent
        c1.calcSum(10,20);
        c1.calcDifference(30, 20);
        c2.calcProduct(30, 20);
    }
}