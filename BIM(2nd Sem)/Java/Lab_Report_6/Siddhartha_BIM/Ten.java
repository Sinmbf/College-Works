// 10. Create a class EmployeeDetails having data member empId, empName,
// empGender, empAddress, and empPosition, constructor to set the details and
// display method to display the details. Create a subclass SalaryInfo that will
// inherit EmployeeDetails having own data member salary which will record
// salary per year, constructor to set the value of salary and method calcTax()
// that deduct the tax on salary and display the final salary. Tax rate is given
// as (if salary <= 400000 tax is 1%, salary between 400001 to 800000 tax is 10%
// and salary > 800000 tax 20%). Now create the object of Salary info and
// demonstrate the scenario.

// Parent class
class EmployeeDetails {
    // Member variable
    private int empId;
    private String empName;
    private String empGender;
    private String empAddress;
    private String empPosition;

    // Constructor to set details
    public EmployeeDetails(int empId, String empName, String empGender, String empAddress, String empPosition) {
        this.empId = empId;
        this.empName = empName;
        this.empGender = empGender;
        this.empAddress = empAddress;
        this.empPosition = empPosition;
    }

    // Method to display the details
    public void displayDetails() {
        System.out.println("Details of employee: ");
        System.out.println("ID: " + empId + "\nName: " + empName + "\nGender: " + empGender + "\nAddress: " + empAddress
                + "\nPosition: " + empPosition);
    }
}

// Child class
class SalaryInfo extends EmployeeDetails {
    // Member variable
    private double salary;

    // Constructor to set value of salary
    public SalaryInfo(double salary, int empId, String empName, String empAddress, String empGender,
            String empPosition) {
        super(empId, empName, empGender, empAddress, empPosition); // Call parent constructor
        this.salary = salary;
    }

    // Method to calculate tax
    public void calcTax() {
        double tax = 0.0;
        if (salary <= 400000) {
            tax = 0.01 * salary;
        } else if (salary <= 800000) {
            tax = 0.1 * salary;
        } else {
            tax = 0.2 * salary;
        }
        // Display final salary
        System.out.println("Final Salary: " + (salary - tax));
    }
}

// Main class
public class Ten {
    public static void main(String[] args) {
        // Create object
        SalaryInfo si = new SalaryInfo(4000000, 101, "Sinmbf", "Dallu", "Male", "CEO");
        // Call method to display employee details
        si.displayDetails();
        si.calcTax();
    }
}