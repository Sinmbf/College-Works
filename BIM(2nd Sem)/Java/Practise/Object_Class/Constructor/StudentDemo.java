// Create a class student with private member variable name, faculty and percentage(int). After this, create a method to
// set, display and return value of instance variable. Now, create two object of student in StudentDemo class that have 
// main method and demonstrate above scenario. Also calculate who get the highest percentage

class Student{
    // Instance Variable
    private String name;
    private String faculty;
    private int percentage;
    
    // Method to set student details
    public void setStudentDetails(String name,String faculty,int percentage){
        this.name=name;
        this.faculty=faculty;
        this.percentage=percentage;
    }
    // Method to display student details
    public void displayStudentDetails(){
        System.out.println("Name: " + this.name + "\nFaculty: " + this.faculty+ "\nPercentage: " + this.percentage);
    }
    // Method to return student name
    public String getStudentName(){
        return this.name;
    }
    // Method to return student faculty
    public String getStudentFaculty(){
        return this.faculty;
    }
    // Method to return student percentage
    public int getStudentPercentage(){
        return this.percentage;
    }
}

// Main Class
public class StudentDemo {
    public static void main(String[]args){
        // Create object for student 1
        Student s1=new Student();
        // Create object for student 2
        Student s2=new Student();
        // Set Details for student 1 and 2
        s1.setStudentDetails("Sinmbf","BIM" , 90);
        s2.setStudentDetails("Lost","BIM" , 100);
        // Display student details
        System.out.println("Student 1: ");
        s1.displayStudentDetails();
        System.out.println("Student 2: ");
        s2.displayStudentDetails();
        // Get student percentage
        int percentage1=s1.getStudentPercentage();
        int percentage2=s2.getStudentPercentage();
        // Find the student with the highest percentage
        if(percentage1>percentage2){
            System.out.println("Student 1 got the highest percentage: " + percentage1 + "%");
        }
        else{
            System.out.println("Student 2 got the highest percentage: " + percentage2 + "%");
        }
    }
}
