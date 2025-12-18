# https://leetcode.com/problems/swap-nodes-in-pairs/description/

'''
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Explanation:


Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Example 4:
Input: head = [1,2,3]
Output: [2,1,3]

 

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
'''


class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy=ListNode(0)
        dummy.next=head
        tail,first=dummy,head

        while first and first.next:
            second=first.next

            tail.next=second
            first.next=second.next
            second.next=first

            tail=first
            first=first.next
        return dummy.next


# Complexity Analysis
# Time Complexity : O(N) where N is the size of the linked list.
# Space Complexity : O(1).

