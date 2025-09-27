class Animal:
  def __init__(self):
    pass
  
  def print_animal(self):
    print("I am from the Animal class")

  def print_animal_two(self):
    print("I am from the Animal class")


class Lion(Animal):
  
  def print_animal(self): # method overriding
    print("I am from the Lion class")


lion = Lion()
lion.print_animal()
lion.print_animal_two()
