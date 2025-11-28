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

