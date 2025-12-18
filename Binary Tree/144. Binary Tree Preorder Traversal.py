# https://leetcode.com/problems/binary-tree-preorder-traversal/description/

'''
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]
Explanation:

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [1,2,4,5,6,7,3,8,9]
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

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        res=[]

        def dfs(root:Optional[TreeNode])->None:
            if not root:
                return
            res.append(root.val)
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        return res


class Solution(object):
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []

        stack, output = [root],[]

        while stack:
            root = stack.pop()
            if root is not None:
                output.append(root.val)
                if root.right is not None:
                    stack.append(root.right)
                if root.left is not None:
                    stack.append(root.left)

        return output
    


# Complexity Analysis
# Time complexity: we visit each node exactly once, thus the time complexity is O(N), where N is the number of nodes, i.e. the size of the tree.
# Space complexity: depending on the tree structure, we could keep up to the entire tree, therefore, the space complexity is O(N).

# Approach 2: Morris traversal
# This approach is based on Morris's article which is intended to optimize the space complexity. The algorithm does not use additional space for the computation, and the memory is only used to keep the output. If one prints the output directly along the computation, the space complexity would be O(1).

