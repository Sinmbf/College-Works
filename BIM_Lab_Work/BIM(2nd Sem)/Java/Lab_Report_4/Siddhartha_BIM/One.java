/*
 
    Create a class student having data member roll(int), name(string), address(string),
    gender(string), and method setData() to set the value of data member and display 
    method that display the data of student. Now create two object of Student and invoke
    set and display method.

 */

class Student {
    // Members
    private int roll;
    private String name;
    private String address;
    private String gender;

    // Method to set the value of member
    public void setData(int roll, String name, String address, String gender) {
        this.roll = roll;
        this.name = name;
        this.address = address;
        this.gender = gender;
    }

    // Method to display the value of member
    public void displayData() {
        System.out.println(
                "Name: " + this.name + "\nRoll No: " + this.roll + "\nAddress: " + this.address + "\nGender: "
                        + this.gender);
    }
}

public class One {
    public static void main(String[] args) {
        // Create object
        Student s1 = new Student();
        // Set value of member
        s1.setData(23, "Siddhartha", "Dallu", "Male");
        // Display data of student
        s1.displayData();
    }
}