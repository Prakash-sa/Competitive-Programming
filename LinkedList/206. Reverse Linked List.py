# https://leetcode.com/problems/reverse-linked-list/description/

'''
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
 
Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 
Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
'''

## iterative
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev=None
        curr=head

        while curr:
            next_tmp=curr.next
            curr.next=prev
            prev=curr
            curr=next_tmp
        return prev
        
# Complexity analysis

# Time complexity : O(n).
# Assume that n is the list's length, the time complexity is O(n).

# Space complexity : O(1).



## recursive
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if (not head) or (not head.next):
            return head

        p=self.reverseList(head.next)
        head.next.next=head
        head.next=None
        return p
        
# Complexity Analysis

# Time complexity : O(n).
# Assume that n is the list's length, the time complexity is O(n).

# Space complexity : O(n).
# The extra space comes from implicit stack space due to recursion. The recursion could go up to n levels deep.