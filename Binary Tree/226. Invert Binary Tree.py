# https://leetcode.com/problems/invert-binary-tree/description/

'''
Given the root of a binary tree, invert the tree, and return its root.

Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:
Input: root = [2,1,3]
Output: [2,3,1]
Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
'''

# iterative

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        
        queue=deque([root])

        while len(queue):
            tmp=queue.popleft()
            tmp.left,tmp.right=tmp.right,tmp.left
            if tmp.left:
                queue.append(tmp.left)
            if tmp.right:
                queue.append(tmp.right)
        return root
        

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        
        root.left,root.right=self.invertTree(root.right),self.invertTree(root.left)
        return root
        
# How it works:
# Base case: If the current node is None, return None
# Recursive case:
# Swap the left and right children by recursively calling invertTree on them
# The assignment root.left, root.right = self.invertTree(root.right), self.invertTree(root.left) handles both the inversion and the recursive calls in one line
# Return the current node after inversion
# Time Complexity: O(n)
# Visits each node exactly once
# Space Complexity: O(h)
# Where h is the height of the tree (due to recursion stack)
# Best case (balanced tree): O(log n)
# Worst case (skewed tree): O(n)
# This recursive approach is more concise and follows the natural recursive structure of binary trees.