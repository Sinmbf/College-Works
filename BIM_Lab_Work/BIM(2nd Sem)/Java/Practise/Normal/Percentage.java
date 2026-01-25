import java.util.*;

public class Percentage{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int totalMarks=0;
        System.out.println("Enter marks in 5 subjects: ");
        for(int i=0;i<=4;i++){
            int marks=sc.nextInt();
            totalMarks+=marks;
        }
        double percentage=((double)totalMarks/500)*100;
        System.out.println("Total Marks: "+ totalMarks);
        System.out.println("Percentage: "+ percentage);
        if(percentage>=80 && percentage<=100){
            System.out.println("Division: Distinction");
        }
        else if(percentage>=60){
            System.out.println("Division: First");
        }
        else if(percentage>=50){
            System.out.println("Division: Second");
        }
        else{
            System.out.println("Fail");
        }
        sc.close();
    }
}