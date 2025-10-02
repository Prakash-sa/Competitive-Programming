class Vehicle:
    def __init__(self):
        self.license_no = None
        self.ticket = None 

    def assign_ticket(self, ticket):
        pass

class Car(Vehicle):
    def assign_ticket(self, ticket):
        pass

class Van(Vehicle):
    def assign_ticket(self, ticket):
        pass

class Truck(Vehicle):
    def assign_ticket(self, ticket):
        pass

class Motorcycle(Vehicle):
    def assign_ticket(self, ticket):
        pass
