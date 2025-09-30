class ParkingLot:
    _instance = None

    def __init__(self):
        self.id = None
        self.name = None
        self.address = None
        self.parking_rate = None

        self.entrances = None       # dict: str -> Entrance
        self.exits = None           # dict: str -> Exit
        self.spots = None           # dict: int -> ParkingSpot
        self.tickets = None         # dict: str -> ParkingTicket
        self.display_boards = None  # list of DisplayBoard

    @classmethod
    def get_instance(cls):
        if cls._instance is None:
            cls._instance = ParkingLot()
        return cls._instance

    def add_entrance(self, entrance):
        pass

    def add_exit(self, exit):
        pass

    def add_parking_spot(self, spot):
        pass

    def add_display_board(self, board):
        pass

    def get_parking_ticket(self, vehicle):
        pass

    def is_full(self, spot_type):
        pass