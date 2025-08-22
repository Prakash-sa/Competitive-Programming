# Many objects in python have built-in iterators. 
# That's why we can conveniently iterate through an array using the key word in.


class ListNode:
    def __init__(self,val):
        self.val=val
        self.next=None

class LinkedList:
    def __init__(self,head):
        self.head=head
        self.cur=None

    def __iter__(self):
        self.cur=self.head
        return self

    def __next__(self):
        if self.cur:
            val=self.cur.val
            self.cur=self.cur.next
            return val
        else:
            raise StopIteration
         
head=ListNode(1)
head.next=ListNode(2)
head.next.next=ListNode(3)
myList=LinkedList(head)

for n in myList:
    print(n)
