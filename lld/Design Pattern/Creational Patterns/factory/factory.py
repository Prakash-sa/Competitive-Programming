class Burger:
    def __init__(self, ingredients):
        self.ingredientes=ingredients

    def print(self):
        print(self.ingredients)


class BurgerFactory:
    def createCheeseBurger(self):
        ingredients=["bun","cheese","beef-patty"]
        return Burger(ingredients)
    
    def createDeluxeBurger(self):
        ingredients=["bun","tomatoe","lettuce","cheese","beef-patty"]
        return Burger(ingredients)
    
    def createVeganBurger(self):
        ingredients=["bun","sepcial-sauce","veggie-patty"]
        return Burger(ingredients)
    

burgerFactory=BurgerFactory()
burgerFactory.createCheeseBurger().print()
burgerFactory.createDeluxeBurger().print()
burgerFactory.createVeganBurger().print()

