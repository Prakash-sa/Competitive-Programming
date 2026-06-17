# https://leetcode.com/problems/recover-binary-search-tree/description/

"""
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Example 1:
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

Constraints:
The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1

Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        x=y=predecessor=pred=None

        while root:
            if root.left:
                predecessor=root.left
                while predecessor.right and predecessor.right!=root:
                    predecessor=predecessor.right
                
                if predecessor.right is None:
                    predecessor.right=root
                    root=root.left
                else:
                    if pred and root.val<pred.val:
                        y=root
                        if x is None:
                            x=pred
                    pred=root

                    predecessor.right=None
                    root=root.right
            else:
                if pred and root.val<pred.val:
                    y=root
                    if x is None:
                        x=pred
                pred=root
                root=root.right

        x.val,y.val=y.val,x.val


# Complexity Analysis

# Time complexity : O(N) since we visit each node up to two times.
# Space complexity : O(1).