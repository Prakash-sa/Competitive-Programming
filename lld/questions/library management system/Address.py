class Address:
    def __init__(self,street_address,city,state,zip_code,country):
        self.street_address=street_address
        self.city=city
        self.state=state
        self.zip_code=zip_code
        self.country=country

class Person:
    def __init__(self,name,address,email,phone):
        self.name=name
        self.address=address
        self.email=email
        self.phone=phone
