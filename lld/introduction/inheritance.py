# Base class (Parent)
class Vehicle():
    def __init__(self, name, model):
        self.name = name
        self.model = model

    def get_name(self):
        print("The car is a", self.name, self.model, end="")

# Single inheritance
# FuelCar class extending from Vehicle class
# Derived class (Child)
class FuelCar(Vehicle):
    def __init__(self, name, model, combust_type):
        self.combust_type = combust_type
        Vehicle.__init__( self,name, model)

    def get_fuel_car(self):
        super().get_name()
        print(", combust type is", self.combust_type, end="")

# Hierarchical inheritance
# Alongside the FuelCar class, the ElectricCar class is also extending from Vehicle class
# Another Derived class (Child)
class ElectricCar(Vehicle):
    def __init__(self, name, model, battery_power):
        self.battery_power = battery_power
        Vehicle.__init__(self, name, model)

    def get_electric_car(self):
        super().get_name()
        print(", battery power is", self.battery_power, end="")

# Multi-level inheritance
# GasolineCar class is derived from the FuelCar class, which is further derived from the Vehicle class
# Derived class (Grandchild)
class GasolineCar(FuelCar):
    def __init__(self, name, model, combust_type, gas_capacity):
            self.gas_capacity = gas_capacity
            FuelCar.__init__(self, name, model, combust_type)
    
    def get_gasoline_car(self):
        super().get_fuel_car()
        print(", gas capacity is",self.gas_capacity)

# Multiple inheritance
# The HybridCar class is derived from two different classes, The GasolineCar class and the ElectricCar class 
# Derived class
class HybridCar(GasolineCar, ElectricCar):

    def __init__(self, name, model, combust_type, battery_power):
        FuelCar.__init__(self, name, model, combust_type)
        ElectricCar.__init__(self,name, model, battery_power)
        self.battery_power = battery_power

    def get_hybrid(self):
        self.get_fuel_car()
        print(", battery power is",self.battery_power)
     
# main
def main():
    print("Single inheritance:")
    Fuel = FuelCar("Honda", "Accord", "Petrol")
    Fuel.get_fuel_car()
    print("\n")

    print("Hierarchical inheritance:")
    Electric = ElectricCar("Tesla", "ModelX", "200MWH")
    Electric.get_electric_car()
    print("\n")

    print("Multi-Level inheritance:")
    Gasoline = GasolineCar("Toyota", "Corolla", "Gasoline", "30 liters")
    Gasoline.get_gasoline_car()
    print("\n")

    print("Multiple inheritance:")
    Hybrid = HybridCar("Toyota", "Prius", "Hybrid", "100MWH")
    Hybrid.get_hybrid()

main()
