# https://leetcode.com/problems/same-tree/description/

'''
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false

Constraints:
The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if not p or not q:
            return False
        if p.val !=q.val:
            return False
        return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)
            
# Complexity Analysis

# Time complexity : O(N),
# where N is a number of nodes in the tree, since one visits
# each node exactly once.
# Space complexity : O(N) in the worst case of completely unbalanced tree, to keep a recursion stack.


# Iterative:

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from collections import deque
from typing import Optional

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        def check(p,q):
            if not p and not q:
                return True
            if not p or not q:
                return False
            if p.val!=q.val:
                return False
            return True

        dq=deque([(p,q)])
        
        while dq:
            tp,tq=dq.popleft()
            if not check(tp,tq):
                return False
            if tp:
                dq.append((tp.left,tq.left))
                dq.append((tp.right,tq.right))

        return True


# Complexity Analysis

# Time complexity : O(N) since each node is visited exactly once.
# Space complexity : O(N) in the worst case, where the tree is a perfect fully balanced binary tree, since BFS will have to store at least an entire level of the tree in the queue, and the last level has O(N) nodes.
