from Door import Door
from Display import Display
from collections import deque

class ElevatorCar:
    def __init__(self, id, num_floors):
        self.id = id
        self.current_floor = 0
        self.state = None
        self.door = Door()
        self.display = Display()
        self.panel = None
        self.request_queue = deque()
        self.load = 0
        self.overloaded = False
        self.maintenance = False

    def get_id(self): return 0
    def get_current_floor(self): return 0
    def get_state(self): return None
    def get_panel(self): return None
    def is_in_maintenance(self): return False
    def is_overloaded(self): return False
    def register_request(self, floor): pass
    def move(self): pass
    def stop(self): pass
    def enter_maintenance(self): pass
    def exit_maintenance(self): pass
    def emergency_stop(self): pass
    def add_load(self, kg): pass
    def remove_load(self, kg): pass
    def get_display(self): return None
    def get_door(self): return None
