class Circle:
    #define data attributes within the constructor
    def __init__(self, r=0):
        self.radius = r
        self.pi = 3.142

    #define methods
    def area(self):
        return self.pi * self.radius * self.radius

    def perimeter(self):
        return 2 * self.pi * self.radius

def main():
    circle = Circle(5)
    print("Area: {:.2f}".format(circle.area()))
    print("Perimeter: {:.2f}".format(circle.perimeter()))

if __name__ == "__main__":
    main()
