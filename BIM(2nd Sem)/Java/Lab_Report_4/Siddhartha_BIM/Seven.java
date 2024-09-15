/* 

    Create a class Product with name, qty and price. Create a parameterized constructor to 
    set the product details. Provide the method getName(), getQty(), and getPrice() that 
    return product name, qty and price. Also create method getTotal() that returns the total
    price. Then create a class ProductDemo with main method that creates two object of Product and find the total price of both products.

*/

class Product {
    // Instance Variable
    private String name;
    private int qty;
    private int price;

    // Parameterized Constructor
    public Product(String name, int qty, int price) {
        this.name = name;
        this.qty = qty;
        this.price = price;
    }

    // Method to get name
    public String getName() {
        return this.name;
    }

    // Method to get qty
    public int getQty() {
        return this.qty;
    }

    // Method to get price
    public int getPrice() {
        return this.price;
    }

    // Method to return total price
    public int getTotalPrice() {
        return (this.price * this.qty);
    }
}

public class Seven {
    public static void main(String[] args) {
        // Create object for product 1
        Product p1 = new Product("Fan", 3, 3400);
        // Create object for product 2
        Product p2 = new Product("Mobile", 2, 42000);
        // Get details of product 1
        String name1 = p1.getName();
        int price1 = p1.getPrice();
        int qty1 = p1.getQty();
        int totalPrice1 = p1.getTotalPrice();
        // Get details of product 2
        String name2 = p2.getName();
        int price2 = p2.getPrice();
        int qty2 = p2.getQty();
        int totalPrice2 = p2.getTotalPrice();
        // Display Product Details
        System.out.println("Details of product 1: ");
        System.out.println(
                "Name: " + name1 + "\nPrice: " + price1 + "\nQuantity: " + qty1 + "\nTotal Price: " + totalPrice1);
        System.out.println("Details of product 2: ");
        System.out.println(
                "Name: " + name2 + "\nPrice: " + price2 + "\nQuantity: " + qty2 + "\nTotal Price: " + totalPrice2);
    }
}
