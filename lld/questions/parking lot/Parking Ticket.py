class ParkingTicket:
    def __init__(self):
        self.ticket_no = None
        self.entry_time = None
        self.exit_time = None
        self.amount = None
        self.status = None  # type: TicketStatus

        self.vehicle = None
        self.payment = None  # type: Payment
        self.entrance = None
        self.exit_ins = None
