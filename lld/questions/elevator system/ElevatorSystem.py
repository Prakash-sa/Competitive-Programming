class ElevatorSystem:
    _system = None

    def __init__(self, floors, cars):
        self.building = None

    @staticmethod
    def get_instance(floors, cars,panels,display): return None
    def get_cars(self): return None
    def get_building(self): return None
    def call_elevator(self, floor_num, direction): pass
    def get_nearest_idle_car(self, floor): return None
    def dispatcher(self): pass
    def monitoring(self): pass


class Building:
    def __init__(self, num_floors, num_cars, num_panels, num_displays_per_floor):
        self.floors = []
        self.cars = []

    def get_floors(self): return None
    def get_cars(self): return None
