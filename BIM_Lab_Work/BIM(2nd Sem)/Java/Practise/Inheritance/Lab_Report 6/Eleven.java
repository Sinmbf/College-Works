class BankAccount {
    // Instance variable
    private int accNo;
    private String name;
    private String address;
    private String phone_no;
    private String gender;

    // Constructor to set instance variable
    public BankAccount(int accNo, String name, String address, String phone_no, String gender) {
        this.accNo = accNo;
        this.name = name;
        this.address = address;
        this.phone_no = phone_no;
        this.gender = gender;
    }

    // Method to display details
    public void displayDetails() {
        System.out.println("Account number :" + accNo + "\nName: " + name + "\nAddress: " + address);
        System.out.println("Phone number: " + phone_no + "\nGender: " + gender);
    }
}

// Sub class
class SavingAccount extends BankAccount {
    // Instance variable
    private double currentAmount;
    private int month;

    // Constructor
    public SavingAccount(int accNo, String name, String address, String phone_no, String gender, int currentAmount,
            int month) {
        super(accNo, name, address, phone_no, gender);
        this.currentAmount = currentAmount;
        this.month = month;
    }

    // Method to calculate total
    public double calcTotal() {
        double bonus = 0.0;
        if (month < 3) {
            bonus = 0.2 * currentAmount;
        } else if (month < 6) {
            bonus = (double) 5 / 100 * currentAmount;
        } else if (month < 12) {
            bonus = (double) 8 / 100 * currentAmount;
        } else {
            bonus = (double) 11.03 / 100 * currentAmount;
        }
        currentAmount += bonus;
        return currentAmount;
    }
}

// Main Class
public class Eleven {
    public static void main(String[] args) {
        // Create instance
        SavingAccount s1 = new SavingAccount(101, "Sinmbf", "Dallu", "9865135874", "Male", 20000, 13);
        // Call parent method
        s1.displayDetails();
        // Call own method
        double total = s1.calcTotal();
        // Display
        System.out.println("Total: " + total);
    }
}
