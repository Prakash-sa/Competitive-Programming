# https://leetcode.com/problems/design-circular-queue/description/

'''
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language. 

 

Example 1:

Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.
'''


class MyCircularQueue:

    def __init__(self, k: int):
        self.k=k
        self.q=[0]*k
        self.front=0
        self.rear=-1
        self.count=0
        # the additional attribute to protect the access of our queue
        self.queueLock = Lock()
        
    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        # automatically acquire the lock when entering the block
        with self.queueLock:
            self.rear=(self.rear+1)%self.k
            self.q[self.rear]=value
            self.count+=1
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.front=(self.front+1)%self.k
        self.count-=1
        return True

    def Front(self) -> int:
        return self.q[self.front] if not self.isEmpty() else -1
        
    def Rear(self) -> int:
        return self.q[self.rear] if not self.isEmpty() else -1

    def isEmpty(self) -> bool:
        return self.count==0

    def isFull(self) -> bool:
        return self.count==self.k
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
# Operation	Your Version	True Circular Queue
# enQueue	O(1) amortized	O(1)
# deQueue	O(n)	O(1)
# Space	Grows to k then fixed	Fixed O(k) from start
# Memory	Fragmented (list resizing)	Contiguous block


class Node:
    def __init__(self, value, nextNode=None):
        self.value = value
        self.next = nextNode

class MyCircularQueue:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self.capacity = k
        self.head = None
        self.tail = None
        self.count = 0

    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self.count == self.capacity:
            return False
        
        if self.count == 0:
            self.head = Node(value)
            self.tail = self.head
        else:
            newNode = Node(value)
            self.tail.next = newNode
            self.tail = newNode
        self.count += 1
        return True


    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.count == 0:
            return False
        self.head = self.head.next
        self.count -= 1
        return True


    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        if self.count == 0:
            return -1
        return self.head.value

    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        # empty queue
        if self.count == 0:
            return -1
        return self.tail.value
    
    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        return self.count == 0

    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        return self.count == self.capacity

# Complexity

# Time complexity: O(1) for each method in our circular queue.
# Space Complexity: The upper bound of the memory consumption for our circular queue would be O(N), same as the array approach. However, it should be more memory efficient as we discussed in the intuition section.