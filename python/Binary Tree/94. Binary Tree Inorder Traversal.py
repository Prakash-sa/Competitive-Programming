# https://leetcode.com/problems/binary-tree-inorder-traversal/description/

'''
Given the root of a binary tree, return the inorder traversal of its nodes' values. 

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]
Explanation:

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]
Explanation:

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 
Follow up: Recursive solution is trivial, could you do it iteratively?
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]

        def dfs(root):
            if not root:
                return
            dfs(root.left)
            ans.append(root.val)
            dfs(root.right)
        dfs(root)
        return ans
        
    
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
#
# Iteratively

class Solution:
    def inorderTraversal(self, root):
        res = []
        stack = []
        curr = root
        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            res.append(curr.val)
            curr = curr.right
        return res


# Complexity Analysis
# Time complexity: O(n)
# Space complexity: O(n)


# Approach 3: Morris Traversal
# In this method, we have to use a new data structure - Threaded Binary Tree, and the strategy is as follows:

# Step 1: Initialize current as root

# Step 2: While current is not NULL,

# If current does not have left child

#     a. Add current’s value

#     b. Go to the right, i.e., current = current.right

# Else

#     a. In current's left subtree, make current the right child of the rightmost node

#     b. Go to this left child, i.e., current = current.left