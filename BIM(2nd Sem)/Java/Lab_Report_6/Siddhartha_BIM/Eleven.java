// 11.	Create a class BankAccount that have data member accNo, Name, address, phone, gender, constructor to set the bank details and showDetails() method to display the account details. Create subclass SavingAccount which inherits BankAccount and have data member currentAmount and month, constructor to set the data member, methods calcTotal() that update the currentAmount by adding the bonus amount and return the result. (if saving month is below 3 month bonus is 2%, if saving month is between 3 to 6 month bonus is 5%, if saving month is between 6 to 12 month bonus is 8% and if saving month is above 1 year bonus is 11.03%).  Now create the object of SavingAccount and demonstrate the scenario.

// Parent class
class BankAccount {
    // Member variable
    private int accNo;
    private String name;
    private String address;
    private String phone;
    private String gender;

    // Constructor to set bank details
    public BankAccount(int accNo, String name, String address, String phone, String gender) {
        this.accNo = accNo;
        this.name = name;
        this.address = address;
        this.phone = phone;
        this.gender = gender;
    }

    // Method to display bank details
    public void showDetails() {
        System.out.println("Bank account details: ");
        System.out.println("Account No: " + accNo + "\nName: " + name + "\nAddress: " + address + "\nPhone: " + phone
                + "\nGender: " + gender);
    }
}

// Child class
class SavingAccount extends BankAccount {
    // Member variable
    private int currentAmount;
    private int month;

    // Constructor to set data member
    public SavingAccount(int currentAmount, int month, int accNo, String name, String address, String phone,
            String gender) {
        super(accNo, name, address, phone, gender); // Call parent constructor
        this.currentAmount = currentAmount;
        this.month = month;
    }

    // Method to calculate total amount
    public double calcTotal() {
        double bonus = 0.00;
        if (month < 3) {
            bonus = 0.02 * currentAmount;
        } else if (month < 6) {
            bonus = 0.05 * currentAmount;
        } else if (month < 12) {
            bonus = 0.08 * currentAmount;
        } else {
            bonus = (double) 11.03 / 100 * currentAmount;
        }
        // Return total amount
        return (currentAmount + bonus);
    }
}

// Main class
public class Eleven {
    public static void main(String[] args) {
        // Create object
        SavingAccount sa = new SavingAccount(500001, 4, 101, "Sinmbf", "Dallu", "9865135874", "Male");
        // Call method
        sa.showDetails();
        double totalAmount = sa.calcTotal();
        System.out.println("Total Amount: " + totalAmount);
    }
}
