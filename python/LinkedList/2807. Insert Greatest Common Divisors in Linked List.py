# https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

'''
Given the head of a linked list head, in which each node contains an integer value.
Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
Return the linked list after insertion.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

Example 1:
Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.
Example 2:
Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.

Constraints:
The number of nodes in the list is in the range [1, 5000].
1 <= Node.val <= 1000
'''



# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tmp=head

        # greatest common divisor using the Euclidean algorithm
        def _gcd(x,y):
            while y!=0:
                x,y=y,x%y
            return x

        while tmp and tmp.next:
            k=_gcd(tmp.val,tmp.next.val)
            tmpNode=ListNode(k)
            tmpNode.next=tmp.next
            tmp.next=tmpNode
            tmp=tmp.next.next
        return head


# Complexity Analysis
# Let n be the number of nodes in the linked list.

# Time complexity: O(n⋅log(min(a,b)))
# The algorithm traverses the list, visiting each node exactly once. This takes linear time.
# The GCD is calculated using the Euclidean algorithm, which has a time complexity of O(log(min(a,b))), where a and b are numbers whose GCD is being calculated.
# Thus, the overall time complexity of the algorithm is O(n⋅log(min(a,b))).

# Space complexity: O(1)
# The iterative implementation of the GCD method has a space complexity of O(1).
