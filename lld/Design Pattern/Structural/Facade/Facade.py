# an outward appearance that is maintained to conceal a less pleasant or creditable reality.
# In the programming world, the "outward appearance" is the class or interface we interact with as programmers. 
# And the "less pleasant reality" is the complexity that is hidden from us.
# So a Facade, is simply a wrapper class that can be used to abstract lower-level details that we don't want 
# to worry about.

# use for the APIs Design

class Array:
    def __init__(self):
        self.capacity=3
        self.length=0
        self.arr=[0]*2
    
    def pushback(self,n):
        if self.length==self.capacity:
            self.resize()

        self.arr[self.length]=n
        self.length+=1

    def resize(self):
        self.capacity=2*self.capacity
        newArr=[0]*self.capacity

        for i in range(self.length):
            newArr[i]=self.arr[i]
        self.arr=newArr

    def popback(self):
        if self.length>0:
            self.length-=1