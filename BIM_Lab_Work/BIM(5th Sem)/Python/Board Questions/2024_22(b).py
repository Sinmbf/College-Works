class Vehicle:
    def __init__(self, speed):
        self.speed = speed

    def display_speed(self):
        print("Speed:", self.speed)


class Car(Vehicle):
    def __init__(self, speed, fuel_type):
        super().__init__(speed)
        self.fuel_type = fuel_type

    def display_car(self):
        print("Fuel Type:", self.fuel_type)


class Truck(Vehicle):
    def __init__(self, speed, fuel_type):
        super().__init__(speed)
        self.fuel_type = fuel_type

    def display_truck(self):
        print("Truck Fuel:", self.fuel_type)


class EVCar(Car):
    def __init__(self, speed, fuel_type):
        super().__init__(speed, fuel_type)

    def charge_battery(self):
        print("Battery Charging...")


# Objects

truck = Truck(80, "Diesel")
ev = EVCar(100,"Electric")



print("\nTruck Details")
truck.display_speed()
truck.display_truck()

print("\nEV Car Details")
ev.display_speed()
ev.display_car()
ev.charge_battery()