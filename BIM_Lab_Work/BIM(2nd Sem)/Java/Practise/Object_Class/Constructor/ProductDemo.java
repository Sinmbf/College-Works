// Create a class Product with instance variable name, qty, price. Create a constructor to initialize value of instance 
// variable and method get() that return value of instance variable, getTotalPrice() that return total price of product
// Now create Product Demo class with main method that create two object of product and calls all the necessary method

import java.util.Scanner;

class Product{
    // Instance Variable
    private String name;
    private int qty;
    private int price;
    
    // Constructor to initialize instance variable
    public Product(String name, int qty, int price){
        this.name=name;
        this.qty=qty;
        this.price=price;
    }

    // Method to return name
    String getProductName(){
        return this.name;
    }

    // Method to return quantity
    int getProductQty(){
        return this.qty;
    }

    // Method to return price 
    int getProductPrice(){
        return this.price;
    }

    // Method to return total price
    int getTotalPrice(){
        return this.price*this.qty;
    }
}

public class ProductDemo {
    public static void main(String[]args){
        // Scanner object
        Scanner sc=new Scanner(System.in);
        // Take input of product 1
        System.out.println("Enter details of product 1: ");
        System.out.println("Name: ");
        String name1=sc.next();
        System.out.println("Quantity: ");
        int qty1=sc.nextInt();
        System.out.println("Price: ");
        int price1=sc.nextInt();
        // Take input of product 2
        System.out.println("Enter details of product 2: ");
        System.out.println("Name: ");
        String name2=sc.next();
        System.out.println("Quantity: ");
        int qty2=sc.nextInt();
        System.out.println("Price: ");
        int price2=sc.nextInt();
        // Create object
        Product p1=new Product(name1,qty1,price1);
        Product p2=new Product(name2,qty2,price2);
        // Get Details of product 1
        String productName1=p1.getProductName();
        int productQty1=p1.getProductQty();
        int productPrice1=p1.getProductPrice();
        // Get Details of product 2
        String productName2=p2.getProductName();
        int productQty2=p2.getProductQty();
        int productPrice2=p2.getProductPrice();
        // Display details of product 1
        System.out.println("Details of product 1: ");
        System.out.println("Product name: " + productName1);
        System.out.println("Product quantity: " + productQty1);
        System.out.println("Product price: " + productPrice1);
        // Display details of product 2
        System.out.println("Details of product 2: ");
        System.out.println("Product name: " + productName2);
        System.out.println("Product quantity: " + productQty2);
        System.out.println("Product price: " + productPrice2);
        // Get total price
        int totalPrice1=p1.getTotalPrice();
        int totalPrice2=p2.getTotalPrice();
        // Display total price
        System.out.println("Total price of product 1: " + totalPrice1);
        System.out.println("Total price of product 2: " + totalPrice2);
        sc.close();
    }
}
