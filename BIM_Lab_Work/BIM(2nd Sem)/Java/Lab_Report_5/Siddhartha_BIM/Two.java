// 2. Create a class Student having data member roll, name, address, faculty,
// grade(string). Create suitable constructor to set the details of student and
// methods findDivision() that calculates the division of student based on grade
// achieved and return the division( if grade=A+ then distinction, if grade=A
// then very good, grade B+ then first division, grade B then second division ,
// grade C then pass in individual subject and if grade D the fail), display()
// method that display the student details and also display the division
// achieved by the student in main method. Now create the instance of two
// students and demonstrate the above scenario.

class Student {
    private int roll;
    private String name;
    private String address;
    private String faculty;
    private String grade;

    // Create constructor to set details
    public Student(int roll, String name, String address, String faculty, String grade) {
        this.roll = roll;
        this.name = name;
        this.address = address;
        this.faculty = faculty;
        this.grade = grade;
    }

    // Methods
    // Method to find division based on grade
    public String findDivision() {
        String grade = this.grade;
        if (grade == "A+") {
            return "Distinction";
        } else if (grade == "A") {
            return "Very Good";
        } else if (grade == "B+") {
            return "First Division";
        } else if (grade == "B") {
            return "Second Division";
        } else if (grade == "C") {
            return "Pass";
        } else if (grade == "D") {
            return "Fail";
        } else {
            return "Invalid";
        }
    }

    // Method to display student details
    public void display() {
        System.out.println("Name: " + this.name + "\nRoll No: " + this.roll + "\nAddress: " + this.address
                + "\nFaculty: " + this.faculty + "\nGrade: " + this.grade);
    }
}

// Main class
public class Two {
    public static void main(String[] args) {
        // Create instance
        Student s1 = new Student(23, "Siddhartha", "Dallu", "BIM", "A+");
        Student s2 = new Student(12, "Raj", "Thamel", "BIM", "D");
        // Find Division
        String division1 = s1.findDivision();
        String division2 = s2.findDivision();
        // Display students details
        System.out.println("Details of student 1: ");
        s1.display();
        System.out.println("Division: " + division1);
        System.out.println("Details of student 2: ");
        s2.display();
        System.out.println("Division: " + division2);
    }
}