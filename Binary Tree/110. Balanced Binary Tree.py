# https://leetcode.com/problems/balanced-binary-tree/description/

'''
Given a binary tree, determine if it is height-balanced.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:
Input: root = []
Output: true

Constraints:
The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
'''

# Given the definition of a balanced tree
# we know that a tree T is not balanced if and only if there is some node
# p∈T such that ∣height(p.left)−height(p.right)∣>1.
# The tree below has each node labeled by its height,
# as well as the unbalanced subtree highlighted.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        
        def dfs(root: Optional[TreeNode])->int:
            if not root:
                return 0
            lh=dfs(root.left)
            if lh==-1:
                return -1
            rh=dfs(root.right)
            if rh==-1:
                return -1
            if abs(lh-rh)>1:
                return -1 
            return max(lh,rh)+1

        return dfs(root)!=-1


# Metric	Complexity	Reason
# Time	O(n)	Each node visited once
# Space	O(h) (O(log n) avg, O(n) worst)	Recursion depth