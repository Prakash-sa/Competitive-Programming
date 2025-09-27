class Sum:
    def addition(self, a, b, c = 0):
        return a + b + c

sum = Sum()
print(sum.addition(14, 35))
print(sum.addition(31, 34, 43))


class Area:
    def calculateArea(self, length, breadth=-1):
        if breadth != -1:
            return length * breadth;
        else:
            return length * length;


area = Area()
print("Area of rectangle = " + str(area.calculateArea(3, 4)))
print("Area of square = " + str(area.calculateArea(6)))