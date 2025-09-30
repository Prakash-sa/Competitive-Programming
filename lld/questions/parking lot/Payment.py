class Payment:
    def __init__(self):
        self.amount = None
        self.status = None  # type: PaymentStatus
        self.timestamp = None

    def initiate_transaction(self):
        pass

class Cash(Payment):
    def initiate_transaction(self):
        pass

class CreditCard(Payment):
    def initiate_transaction(self):
        pass
