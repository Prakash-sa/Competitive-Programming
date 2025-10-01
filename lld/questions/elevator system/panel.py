class ElevatorPanel:
    def __init__(self,num_floors):
        self.floor_button=[]
        self.open_button=None
        self.close_button=None
        self.emergency_button=None

    def get_floor_buttons(self):
        return self.floor_buttons
    
    def get_open_button(self):
        return self.open_button
    
    def get_close_button(self):
        return self.close_button
    
    def get_emergency_button(self):
        return self.emergency_button
    
    def enter_emergency(self):
        pass

    def exit_emergency(self):
        pass

class HallPanel:
    def __init__(self,floor_number,top_floor):
        self.up=None
        self.down=None

    def get_up_button(self):
        return self.up
    
    def get_down_button(self):
        return self.down
    