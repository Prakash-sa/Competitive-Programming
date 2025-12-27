# https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

'''
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

Constraints:
The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    maxPath=-math.inf
    def gainFromSubtree(self,node):
        if not node:
            return 0
        
        left=max(self.gainFromSubtree(node.left),0)
        right=max(self.gainFromSubtree(node.right),0)
        self.maxPath=max(self.maxPath,left+right+node.val)
        return max(left+node.val,right+node.val)
    
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.maxPath=-math.inf
        self.gainFromSubtree(root)
        return self.maxPath



# Complexity Analysis
# Let n be the number of nodes in the tree.

# Time complexity: O(n)
# Each node in the tree is visited only once. During a visit, we perform constant time operations, including two recursive calls and calculating the max path sum for the current node. So the time complexity is O(n).

# Space complexity: O(n)
# We don't use any auxiliary data structure, but the recursive call stack can go as deep as the tree's height. In the worst case, the tree is a linked list, so the height is n. Therefore, the space complexity is O(n).
