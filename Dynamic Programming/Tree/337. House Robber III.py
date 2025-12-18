# https://leetcode.com/problems/house-robber-iii/description/
# https://www.youtube.com/watch?v=nHR8ytpzz7c

'''
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 

Example 1:


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:


Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        
        def dfs(root):
            if not root:
                return [0,0]
            
            leftPair=dfs(root.left)
            rightPair=dfs(root.right)

            withRoot=root.val+leftPair[1]+rightPair[1]
            withoutRoot=max(leftPair)+max(rightPair)
            return [withRoot,withoutRoot]
        return max(dfs(root))

# Complexity Analysis

# Let N be the number of nodes in the binary tree.

# Time complexity: O(N) since we visit all nodes once.

# Space complexity: O(N) since we need stacks to do recursion, and the maximum depth of the recursion is the height of the tree, which is O(N) in the worst case and O(log(N)) in the best case.