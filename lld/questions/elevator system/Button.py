from abc import ABC, abstractmethod


class Button(ABC):
    def __init__(self):
        self.pressed=False
    
    def press_down(self):
        pass

    def reset(self):
        pass

    @abstractmethod
    def is_pressed(self):
        pass

class DoorButton(Button):
    def is_pressed(self):
        return self.pressed
    
class HallButton(Button):
    def __init__(self,direction):
        super().__init__()
        self.direction=direction

    def get_direction(self):
        return self.direction
    
    def is_pressed(self):
        return False
    
class ElevatorButton(Button):
    def __init__(self,floor):
        super().__init__()
        self.destination_floor=floor
    
    def get_destination_floor(self):
        return self.destination_floor

    def is_pressed(self):
        return False
    
class EmergencyButton(Button):
    def get_pressed(self):
        return False
    
    def set_pressed(self,val):
        pass

    def is_pressed(self):
        return False
    

