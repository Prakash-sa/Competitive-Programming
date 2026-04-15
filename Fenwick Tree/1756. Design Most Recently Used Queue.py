# https://leetcode.com/problems/design-most-recently-used-queue/description/

'''
Design a queue-like data structure that moves the most recently used element to the end of the queue.

Implement the MRUQueue class:

MRUQueue(int n) constructs the MRUQueue with n elements: [1,2,3,...,n].
int fetch(int k) moves the kth element (1-indexed) to the end of the queue and returns it.
 

Example 1:

Input:
["MRUQueue", "fetch", "fetch", "fetch", "fetch"]
[[8], [3], [5], [2], [8]]
Output:
[null, 3, 6, 2, 2]

Explanation:
MRUQueue mRUQueue = new MRUQueue(8); // Initializes the queue to [1,2,3,4,5,6,7,8].
mRUQueue.fetch(3); // Moves the 3rd element (3) to the end of the queue to become [1,2,4,5,6,7,8,3] and returns it.
mRUQueue.fetch(5); // Moves the 5th element (6) to the end of the queue to become [1,2,4,5,7,8,3,6] and returns it.
mRUQueue.fetch(2); // Moves the 2nd element (2) to the end of the queue to become [1,4,5,7,8,3,6,2] and returns it.
mRUQueue.fetch(8); // The 8th element (2) is already at the end of the queue so just return it.
 

Constraints:

1 <= n <= 2000
1 <= k <= n
At most 2000 calls will be made to fetch. 

Follow up: Finding an O(n) algorithm per fetch is a bit easy. Can you find an algorithm with a better complexity for each fetch call?
'''

class Fenwick:
    def __init__(self,n):
        self.n=n
        self.bit=[0]*(n+1)

    def add(self,i,delta):
        while i<=self.n:
            self.bit[i]+=delta
            i+=i&-i
        
    def sum(self,i):
        res=0
        while i>0:
            res+=self.bit[i]
            i-=i&-i
        return res
    
    def kth(self,k):
        idx=0
        bit_mask=1<<(self.n.bit_length())
        while bit_mask:
            nxt=idx+bit_mask
            if nxt<=self.n and self.bit[nxt]<k:
                idx=nxt
                k-=self.bit[nxt]
            bit_mask>>=1
        return idx+1

    def kth(self,k):
        idx=0
        bit_mask=1<<(self.n.bit_length())
        while bit_mask:
            nxt=idx+bit_mask
            if nxt<=self.n and self.bit[nxt]<k:
                idx=nxt
                k-=self.bit[nxt]
            bit_mask>>=1
        return idx+1

class MRUQueue:

    def __init__(self, n: int):
        self.size=n
        self.vals=[0]*(n+2001)
        self.tree=Fenwick(n+2000)

        for i in range(1,n+1):
            self.vals[i]=i
            self.tree.add(i,1)

    def fetch(self, k: int) -> int:
        idx=self.tree.kth(k)
        val=self.vals[idx]

        self.tree.add(idx,-1)
        self.size+=1
        self.vals[self.size]=val
        self.tree.add(self.size,1)
        return val


# Your MRUQueue object will be instantiated and called as such:
# obj = MRUQueue(n)
# param_1 = obj.fetch(k)

'''
Complexity Analysis
Let n be the size of the queue.

Time Complexity: O(log^2n)

The time complexity of the MRUQueue operations is determined by the use of a Fenwick Tree (Binary Indexed Tree) and binary search. 
The Fenwick Tree enables efficient prefix sum calculations and updates, while binary search is used to locate the k-th element in the queue.
Initialization (MRUQueue(int n)): During initialization, the Fenwick Tree and the values array are set up. 
Each of the n elements is inserted into the Fenwick Tree using the insert operation, which takes O(logn) time per insertion. 
Since there are n elements, the total time complexity for initialization is O(nlogn).

Space Complexity: O(n+f)
'''
