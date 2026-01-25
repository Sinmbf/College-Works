class Calculation{
    // Argument and return type
    public int AddTwoNum(int n1,int n2){
        return (n1+n2);
    }

    // Argument and no return type
    public void ProductOfTwoNum(int n1,int n2){
        System.out.println("Product: " + (n1*n2));
    }

    // No Argument and no return type
    public void DisplayMessage(){
        System.out.println("Hello! You called me?");
    }

    // No Argument but has return type
    public String ReceiveMessage(){
        return ("Why did you call me?");
    }

    // Method to print Even
    public void PrintEven(int n1,int n2){
        if(n1>n2){
            int temp=n1;
            n1=n2;
            n2=temp;
        }
        System.out.println("Even numbers from " + n1 +" to " + n2);
        for(int i=n1;i<=n2;i++){
            if(i%2==0){
                System.out.print(i + "\t");
            }
        }
    }

    // Method to determine prime
    public String DeterminePrime(int n){
        boolean isPrime=true;
        for(int i=2;i<n;i++){
            if(n%i==0){
                isPrime=false;
            }
        }
        if(isPrime && n!=2){
            return (n+ " is Prime");
        }
        else{
            return (n+ " is not prime");
        }
    }
}

public class MethodDemo {
    public static void main(String[]args){
        // Create object
        Calculation calc=new Calculation();
        // Call methods
        int sum=calc.AddTwoNum(3,4);
        calc.ProductOfTwoNum(4, 5);
        calc.DisplayMessage();
        String str=calc.ReceiveMessage();
        System.out.println(str);
        System.out.println("Sum: " + sum);
        calc.PrintEven(10,1);
        String isPrime=calc.DeterminePrime(15);
        System.out.println("\n"+isPrime);
    }
}
