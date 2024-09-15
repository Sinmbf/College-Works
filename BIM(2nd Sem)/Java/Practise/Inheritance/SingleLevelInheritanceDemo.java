class Vehicle{
    int reg_no;
    String name;
    String brand;
    // Method to set vehicle details
    public void setVehicle(int reg_no,String name,String brand){
        this.reg_no=reg_no;
        this.name=name;
        this.brand=brand;
    }
    // Method to display vehicle details
    public void displayVehicle(){
        System.out.println("Reg No: "+this.reg_no);
        System.out.println("Name: "+this.name);
        System.out.println("Brand: "+this.brand);
    }
}

// Creating child class
class Car extends Vehicle{
    int milege;
    int price;
    // Method to get car details
    public void setCar(int milege,int price){
        this.milege=milege;
        this.price=price;
    }
    // Method to show car details
    public void displayCar(){
        System.out.println("Milege: " + this.milege);
        System.out.println("Price: " + this.price);
    }
}

// Main Class
public class SingleLevelInheritanceDemo {
    public static void main(String[]args){
        Car c1=new Car();
        // Method of parent class
        c1.setVehicle(123,"Taxi","Tata");
        c1.displayVehicle();
        // Own method
        c1.setCar(30,1000000);
        c1.displayCar();
    }
}
