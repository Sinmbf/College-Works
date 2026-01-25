import java.util.Scanner;

public class MultiDimArrayDemo {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        // Take input
        System.out.println("Enter the number of rows and columns: ");
        int rows=sc.nextInt();
        int columns=sc.nextInt();
        int [][] multiArr=new int[rows][columns];
        System.out.println("Enter " + (rows*columns) + " values: ");
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                multiArr[i][j]=sc.nextInt();
            }
        }
        // Display
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                System.out.println(multiArr[i][j]);
            }
        }
        sc.close();

    }   
}
