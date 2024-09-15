// 6.	Create a class Book with member variables book_id and pages. Then create a subclass FictionBooks of Book with member variable called name. Create some instance of FictionBook and set the value of both subclass and superclass and display all member variables that have been initialized.

// Parent class
class Book {
    // Member variable
    private int book_id;
    private int pages;

    // Constructor to set member variable
    public Book(int book_id, int pages) {
        this.book_id = book_id;
        this.pages = pages;
    }

    // Method to display member variables
    public void displayMembers() {
        System.out.println("Book Id: " + book_id + "\nPages: " + pages);
    }
}

// Child class
class FictionBooks extends Book {
    // Member variable
    private String name;

    // Constructor to set member variable
    public FictionBooks(String name, int book_id, int pages) {
        super(book_id, pages); // Call parent constructor
        this.name = name;
    }

    // Method to display member variables
    public void displayMembers() {
        super.displayMembers(); // Call parent method
        System.out.println("Name: " + name);
    }
}

// Main Class
public class Six {
    public static void main(String[] args) {
        // Create object (object) of child
        FictionBooks fb1 = new FictionBooks("The Alchemist", 101, 300);
        FictionBooks fb2 = new FictionBooks("Atomic Habits", 102, 250);
        // Call method to display book details
        System.out.println("Details of book 1: ");
        fb1.displayMembers();
        System.out.println("Details of book 2: ");
        fb2.displayMembers();

    }
}
