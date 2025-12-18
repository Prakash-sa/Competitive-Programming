# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

'''
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        parent_val=root.val

        p_val=p.val
        q_val=q.val

        if p_val>parent_val and q_val > parent_val:
            return self.lowestCommonAncestor(root.right,p,q)
        elif p_val<parent_val and q_val<parent_val:
            return self.lowestCommonAncestor(root.left,p,q)
        else:
            return root

# Complexity Analysis
# Time Complexity: O(N), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.
# Space Complexity: O(N). This is because the maximum amount of space utilized by the recursion stack would be N since the height of a skewed BST could be N.



# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        node=root
        p_val=p.val
        q_val=q.val

        while node:
            parent_val=node.val
            if p_val>parent_val and q_val>parent_val:
                node=node.right
            elif p_val<parent_val and q_val<parent_val:
                node=node.left
            else:
                return node

# Complexity Analysis

# Time Complexity : O(N), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.
# Space Complexity : O(1).
