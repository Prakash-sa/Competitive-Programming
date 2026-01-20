# https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

'''
You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.
You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.
Implement the KthLargest class:
KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.

Example 1:
Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output: [null, 4, 5, 5, 8, 8]
Explanation:
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8

Example 2:
Input:
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]
Output: [null, 7, 7, 7, 8]
Explanation:
KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8
 

Constraints:
0 <= nums.length <= 104
1 <= k <= nums.length + 1
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
'''

from heapq import heappush,heappop
from collections import List

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k=k
        self.min_heap=[]

        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        if len(self.min_heap)<self.k or self.min_heap[0]<val:
            heappush(self.min_heap,val)
            if len(self.min_heap)>self.k:
                heappop(self.min_heap)
        return self.min_heap[0]
        

# Complexity Analysis
# Let M be the size of the initial stream nums given in the constructor, and let N be the number of calls to add.
# Time Complexity: O((M+N)⋅logk)
# The add function involves adding and removing an element from a heap of size k, which is an O(logk) operation. Since the add function is called N times, the total time complexity for all add calls is O(N⋅logk).
# The constructor also calls add M times to initialize the heap, leading to a time complexity of O(M⋅logk).
# Therefore, the overall time complexity is O((M+N)⋅logk).

# Space Complexity: O(k)
# The minHeap maintains at most k elements, so the space complexity is O(k).
