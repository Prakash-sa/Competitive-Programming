# https://leetcode.com/problems/merge-k-sorted-lists/description/
# https://www.youtube.com/watch?v=RyrVWP76lVo

'''
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
 

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:
Input: lists = []
Output: []
Example 3:
Input: lists = [[]]
Output: []

Constraints:
k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        h=[]

        for i,node in enumerate(lists):
            if node:
                heappush(h,(node.val,i,node))

        dummy=ListNode()
        tail=dummy
        while h:
            val,i,node=heappop(h)
            tail.next=node
            tail=tail.next
            if node.next:
                heappush(h,(node.next.val,i,node.next))
        tail.next=None
        return dummy.next


# Use a min heap to always extract the smallest head among k lists.
# Time O(Nlogk). Space O(k).
# Produces a single sorted linked list.


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge2Lists(self, l1, l2):
        head = point = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                point.next = l1
                l1 = l1.next
            else:
                point.next = l2
                l2 = l1
                l1 = point.next.next
            point = point.next
        if not l1:
            point.next = l2
        else:
            point.next = l1
        return head.next

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        amount = len(lists)
        interval = 1

        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0] if amount > 0 else None

"""
Complexity Analysis

Time complexity : O(Nlogk) where k is the number of linked lists.

We can merge two sorted linked list in O(n) time where n is the total number of nodes in two lists.
Sum up the merge process and we can get: O(∑i=1log2kN)=O(Nlogk)

Space complexity : O(1)
We can merge two sorted linked lists in O(1) space.
"""
