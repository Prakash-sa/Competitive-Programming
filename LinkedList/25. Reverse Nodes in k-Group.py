# https://leetcode.com/problems/reverse-nodes-in-k-group/description/

'''
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 
Follow-up: Can you solve the problem in O(1) extra memory space?
'''



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseLL(self,head,k):
        new_head,ptr=None,head
        while k:
            next_node=ptr.next
            ptr.next=new_head
            new_head=ptr
            ptr=next_node
            k-=1
        return new_head

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        ptr=head
        ktail=None
        new_head=None
        while ptr:
            count=0
            ptr=head
            while count<k and ptr:
                ptr=ptr.next
                count+=1
            if count==k:
                revHead=self.reverseLL(head,k)
                if not new_head:
                    new_head=revHead
                if ktail:
                    ktail.next=revHead
                ktail=head
                head=ptr
        if ktail:
            ktail.next=head
        return new_head if new_head else head

# Time Complexity: O(N) since we process each node exactly twice. Once when we are counting the number of nodes in each recursive call, and then once when we are actually reversing the sub-list.
# Space Complexity: O(1).
