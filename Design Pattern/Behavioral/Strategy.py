# A Class may have different behaviour, or invoke a different method based on something we define (i.e. a Strategy).
# For example, we can filter an array by removing positive values; or we could filter it by removing all odd values. 
# These are two filtering strategies we could implement, but we could add many more.


from abc import ABC,abstractmethod

class FilterStrategy(ABC):
    @abstractmethod
    def removeValue(self,val):
        pass

class RemoveNegativeStrategy(FilterStrategy):
    def removeValue(self,val):
        return val<0
    
class RemoveOddStrategy(FilterStrategy):
    def removeValue(self,val):
        return abs(val)%2;

class Values:
    def __init__(self,vals):
        self.vals=vals

    def filter(self,strategy):
        res=[]
        for n in self.vals:
            if not strategy.removeValue(n):
                res.append(n)
        return res
    

value=Values([-7,-4,0,2,6,9])
print(value.filter(RemoveNegativeStrategy))
print(value.filter(RemoveOddStrategy))
