class OuterClass{
    private int n1;
    public void setOuter(int n1){
        this.n1=n1;
    }
    public void displayOuter(){
        System.out.println("Value of n1: " + this.n1);
    }
    // Access Inner Class
    public void accessInner(){
        // To access inner class, create it's object
        InnerClass i1=new InnerClass();
        i1.setInner(1000);
        i1.displayInner();
    }

    // Inner Class
    private class InnerClass{
        private int n2;
        public void setInner(int n2){
            this.n2=n2;
        }
        public void displayInner(){
            // Accessing own method + variable
            System.out.println("Value of n2: " + n2);
            System.out.println("Accessing outer class: ");
            n1=100;
            setOuter(1000);
            displayOuter();
        }
    }
}

public class NestedClassDemo {
    public static void main(String[]args){
        // InnerClass i2=new InnerClass(); // error
        OuterClass o1= new OuterClass();
        o1.setOuter(10);
        o1.displayOuter();
        o1.accessInner();
    }
}
