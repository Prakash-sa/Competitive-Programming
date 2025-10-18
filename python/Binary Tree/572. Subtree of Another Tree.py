# https://leetcode.com/problems/subtree-of-another-tree/description/

'''
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

Constraints:
The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isMatch(self,root,subroot):
        if not (root and subroot):
            return root is subroot
        return (root.val==subroot.val) and self.isMatch(root.right,subroot.right) and self.isMatch(root.left,subroot.left)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if self.isMatch(root,subRoot):
            return True
        
        if not root:
            return False

        return self.isMatch(root.left,subRoot) or self.isMatch(root.right,subRoot)

# Naive approach, O(|s| * |t|)


