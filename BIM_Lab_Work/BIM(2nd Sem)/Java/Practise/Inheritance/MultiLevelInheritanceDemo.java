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

// Creating child class of Vehicle
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

// Creating child class of Car
class ElectricCar extends Car{
    int batteryCapacity;
    // Method to set battery capacity
    public void setElectricCar(int batteryCapacity){
        this.batteryCapacity=batteryCapacity;
    }
    // Method to display battery capacity
    public void displayElectricCar(){
        System.out.println("Battery Capacity: " + this.batteryCapacity);
    }
}

// Main Class
public class MultiLevelInheritanceDemo {
    public static void main(String[]args){
        ElectricCar e1=new ElectricCar();
        // Parent method
        e1.setVehicle(214,"Taxi","Tata");
        e1.setCar(120,30000000);
        e1.displayCar();
        // Own method
        e1.setElectricCar(140);
        e1.displayElectricCar();
    }
}
