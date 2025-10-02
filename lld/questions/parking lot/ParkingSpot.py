class ParkingSpot:
    def __init__(self):
        self.id = None
        self.is_free = None
        self.vehicle = None 

    def assign_vehicle(self, vehicle):
        pass

    def remove_vehicle(self):
        pass

class Handicapped(ParkingSpot):
    def assign_vehicle(self, vehicle):
        pass

class Compact(ParkingSpot):
    def assign_vehicle(self, vehicle):
        pass

class Large(ParkingSpot):
    def assign_vehicle(self, vehicle):
        pass

class MotorcycleSpot(ParkingSpot):
    def assign_vehicle(self, vehicle):
        pass
