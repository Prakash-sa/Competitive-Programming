class Payment:
    def __init__(self):
        self.amount = None
        self.status = None
        self.timestamp = None

    def initiate_transaction(self):
        pass

class Cash(Payment):
    def initiate_transaction(self):
        pass

class CreditCard(Payment):
    def initiate_transaction(self):
        pass
