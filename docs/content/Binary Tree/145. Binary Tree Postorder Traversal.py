# https://leetcode.com/problems/binary-tree-postorder-traversal/description/

'''
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
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
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res=[]
        if not root:
            return res

        def post(root):

            if root.left:
                post(root.left)
            if root.right:
                post(root.right)
            res.append(root.val)
        
        post(root)
        return res






# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        res = []
        stack = []
        last_visited = None
        current = root
        
        while stack or current:
            # Go to the leftmost node
            if current:
                stack.append(current)
                current = current.left
            else:
                # Peek at the node on top of stack
                peek_node = stack[-1]
                # If right child exists and hasn't been processed yet
                if peek_node.right and last_visited != peek_node.right:
                    current = peek_node.right
                else:
                    # Process the node (both children done)
                    res.append(peek_node.val)
                    last_visited = stack.pop()
        
        return res
    

# Time Complexity: O(n) - visit each node once
# Space Complexity: O(h) for first approach
