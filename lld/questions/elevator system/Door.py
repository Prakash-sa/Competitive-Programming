class Door:
    def __init__(self):
        self.state = None

    def open(self): pass
    def close(self): pass
    def is_open(self): return False
    def get_state(self): return None


class Floor:
    def __init__(self, floor_number, num_panels):
        self.floor_number = floor_number
        self.panels = []
        self.display = None

    def get_floor_number(self): return 0
    def get_panels(self): return None
    def get_panel(self, index): return None
    def get_display(self): return None
