class Display:
    def __init__(self):
        self.floor=0
        self.load=0
        self.direction=None
        self.state=None
        self.maintanence=False
        self.overload=False

    def update(self,f,direction,load,state,overload,maintanence):
        pass

    def show_elevator_display(self,car_id):
        pass

    