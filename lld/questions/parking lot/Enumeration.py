from enum import Enum, auto

class PaymentStatus(Enum):
    COMPLETED = auto()
    FAILED = auto()
    PENDING = auto()
    UNPAID = auto()
    REFUNDED = auto()

class AccountStatus(Enum):
    ACTIVE = auto()
    CLOSED = auto()
    CANCELED = auto()
    BLACKLISTED = auto()
    NONE = auto()

class TicketStatus(Enum):
    ISSUED = auto()
    IN_USE = auto()
    PAID = auto()
    VALIDATED = auto()
    CANCELED = auto()
    REFUNDED = auto()

class Person:
    def __init__(self):
        self.name = None
        self.address = None
        self.phone = None
        self.email = None

class Address:
    def __init__(self):
        self.zip_code = None
        self.street = None
        self.city = None
        self.state = None
        self.country = None
