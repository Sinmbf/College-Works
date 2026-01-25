// Create a class vehicle with instance variable name, brand, taxPrice. Create methods setVehicleDetails to set value  
// of instance variable and method get() that return value of instance variable. Now create vehicleDemo class with main
// method that create two object of vehicle and display name and brand of vehicle that pays more tax.



class Vehicle{
    // Instance Variable
    private String name;
    private String brand;
    private double taxPrice;
    
    // Constructor to initialize instance variable
    public void setVehicleDetails(String name, String brand, int taxPrice){
        this.name=name;
        this.brand=brand;
        this.taxPrice=taxPrice;
    }

    // Method to return name
    String getVehicleName(){
        return this.name;
    }

    // Method to return quantity
    String getVehicleBrand(){
        return this.brand;
    }

    // Method to return price 
    double getVehicleTaxPrice(){
        return this.taxPrice;
    }

}

public class VehicleDemo {
    public static void main(String[]args){
        // Create object
        Vehicle v1=new Vehicle();
        Vehicle v2=new Vehicle();
        // Set details of both vehicles
        v1.setVehicleDetails("Lamborghini","CCC",2000002);
        v2.setVehicleDetails("TATA","CDC",1500000);
        // Get details of vehicle 1
        String vehicleName1=v1.getVehicleName();
        String vehicleBrand1=v1.getVehicleBrand();
        // Get details of vehicle 2
        String vehicleName2=v2.getVehicleName();
        String vehicleBrand2=v2.getVehicleBrand();
        // Get tax price of both vehicles
        double taxPrice1=v1.getVehicleTaxPrice();
        double taxPrice2=v2.getVehicleTaxPrice();
        // Display vehicle with the highest tax
        System.out.println("Vehicle with the highest tax: ");
        if(taxPrice1>taxPrice2){
            System.out.println("Vehicle Name: " + vehicleName1 + "\nVehicle Brand: " + vehicleBrand1);
            System.out.println("Vehicle Tax: " + taxPrice1);
        }
        else{
            System.out.println("Vehicle Name: " + vehicleName2 + "\nVehicle Brand: " + vehicleBrand2);
            System.out.println("Vehicle Tax: " + taxPrice2);
        }
    }
}

