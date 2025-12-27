# https://leetcode.com/problems/symmetric-tree/

'''
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isMirror(self,tree_left,tree_right):
        if not tree_left and not tree_right:
            return True
        if not tree_left or not tree_right:
            return False
        if tree_left.val!=tree_right.val:
            return False
        check=self.isMirror(tree_left.left,tree_right.right) and self.isMirror(tree_left.right,tree_right.left)
        return check

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        return self.isMirror(root.left,root.right)


# Python3
class Solution:
    def isSymmetric(self, root):
        q = [root, root]
        while q:
            t1 = q.pop(0)
            t2 = q.pop(0)
            if t1 is None and t2 is None:
                continue
            if t1 is None or t2 is None:
                return False
            if t1.val != t2.val:
                return False
            q.append(t1.left)
            q.append(t2.right)
            q.append(t1.right)
            q.append(t2.left)
        return True
    
# Complexity Analysis

# Time complexity: O(n). Because we traverse the entire input tree once, the total run time is O(n), where n is the total number of nodes in the tree.

# Space complexity: There is additional space required for the search queue. In the worst case, we have to insert O(n) nodes in the queue. Therefore, space complexity is O(n).