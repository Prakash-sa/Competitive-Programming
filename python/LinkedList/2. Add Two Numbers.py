# https://leetcode.com/problems/add-two-numbers/description/

'''
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
'''


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry=0
        dummy=ListNode(0)
        curr=dummy

        while l1 or l2 or carry:
            l1Val=l1.val if l1 else 0
            l2Val=l2.val if l2 else 0
            k=l1Val+l2Val+carry
            carry=k//10
            newNode=ListNode(k%10)
            curr.next=newNode
            curr=newNode
            l1=l1.next if l1 else None
            l2=l2.next if l2 else None
        
        return dummy.next



# Complexity Analysis
# Time complexity : O(max(m,n)). Assume that m and n represents the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.
# Space complexity : O(1). The length of the new list is at most max(m,n)+1 However, we don't count the answer as part of the space complexity.

# Follow up
# What if the the digits in the linked list are stored in non-reversed order? For example:
# (3→4→2)+(4→6→5)=8→0→7

