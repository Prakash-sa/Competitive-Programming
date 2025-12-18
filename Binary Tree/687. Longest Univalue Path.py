# https://leetcode.com/problems/longest-univalue-path/description/

'''
Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.
The length of the path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [5,4,5,1,1,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 5).

Example 2:
Input: root = [1,4,5,4,4,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 4).

Constraints:
The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
The depth of the tree will not exceed 1000.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        ans=0
        if not root:
            return 0
        def dfs(root,val):
            nonlocal ans
            if not root:
                return 0
            l=dfs(root.left,root.val)
            r=dfs(root.right,root.val)
            ans=max(ans,l+r)
            if root.val==val:
                return max(l,r)+1
            return 0
        dfs(root,root.val)
        return ans


# Complexity Analysis:
# Here, N is the number of nodes in the binary tree.
# Time complexity: O(N)
# We are iterating over each node only once and hence the time complexity is equal to O(N).
# Space complexity: O(N)