# https://leetcode.com/problems/validate-binary-search-tree/description/

'''
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees. 

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:
The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
'''
from typing import Optional
import math

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def validate(self,root,low=-math.inf, high=math.inf):
        if not root:
            return True        
        if root.val<=low or root.val>=high:
            return False
        return self.validate(root.left,low,root.val) and self.validate(root.right,root.val,high) 

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.validate(root)


# Complexity Analysis:
# Time complexity: O(N) since we visit each node exactly once.
# Space complexity: O(N) since we keep up to the entire tree.

class Solution:

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        stack=[]
        prev=-math.inf

        while stack or root:
            while root:
                stack.append(root)
                root=root.left
            root=stack.pop()
            if root.val<=prev:
                return False
            prev=root.val
            root=root.right
        return True

