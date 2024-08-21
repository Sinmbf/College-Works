// 8.	Create a class ExamDept which hold the details of student like roll, name, address and faculty and also have methods to set the values of student and display the details of student. Create a subclass Result that inherits Exam dept which have data member to hold marks of five subject and method setMarks() to set the marks of 5 subject, calcPercentage() that calculate the total marks, percentage and division achieved by students and display the achieved results.  Now create the object of Result and demonstrate the above scenario. 

// Parent class
class ExamDept {
    // Member variables
    private int roll;
    private String name;
    private String address;
    private String faculty;

    // Method to set member variable
    public void setStudentDetails(int roll, String name, String address, String faculty) {
        this.roll = roll;
        this.name = name;
        this.address = address;
        this.faculty = faculty;
    }

    // Method to display student details
    public void displayStudentDetails() {
        System.out.println("Student Details: ");
        System.out.println("Name: " + name + "\nRoll No: " + roll + "\nAddress: " + address + "\nFaculty: " + faculty);
    }
}

// Child class
class Result extends ExamDept {
    // Member variable
    int[] marksArr = new int[5];

    // Method to set marks
    public void setMarks(int[] marksArr) {
        for (int i = 0; i < 5; i++) {
            this.marksArr[i] = marksArr[i];
        }
    }

    // Method to calculate percentage
    public void calcPercentage() {
        int totalMarksObtained = 0;
        float percentage = 0.0f;
        for (int arr : marksArr) {
            // Calculate total marks
            totalMarksObtained += arr;
            // Calculate percentage
            // Assume full marks of all subject to be 100 (5 subjects so 5*100=500)
            percentage = (float) totalMarksObtained / 500 * 100;
        }
        // Calculate division
        String division = " ";
        if (percentage >= 90 && percentage <= 100) {
            division = "A+";
        } else if (percentage >= 80) {
            division = "A";
        } else if (percentage >= 70) {
            division = "B+";
        } else if (percentage >= 60) {
            division = "B";
        } else if (percentage >= 50) {
            division = "C";
        } else {
            division = "Fail";
        }
        // Display the result
        System.out.println("Result obtained: ");
        System.out.println("Percentage: " + percentage + "%" + "\nDivision: " + division);
    }
}

// Main Class
public class Eight {
    public static void main(String[] args) {
        // Create object
        Result rs = new Result();
        // Marks array
        int marksArr[] = { 98, 100, 94, 82, 89 };
        // Call methods
        rs.setStudentDetails(23, "Sinmbf", "Dallu", "BIM");
        rs.setMarks(marksArr);
        // Display result and student details
        rs.displayStudentDetails();
        rs.calcPercentage();
    }
}
