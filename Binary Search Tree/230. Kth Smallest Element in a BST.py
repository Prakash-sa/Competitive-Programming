# https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

'''
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
'''

# Iterative:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack=[]

        while True:
            while root:
                stack.append(root)
                root=root.left
            root=stack.pop()
            k-=1
            if not k:
                return root.val
            root=root.right
        return -1

# Complexity Analysis
# Time complexity : O(N) to build a traversal.
# Space complexity : O(N) to keep an inorder traversal.

# recursive

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.count=0
        self.result=None
        def traversal(root):
            if not root:
                return
            traversal(root.left)
            self.count+=1
            if self.count==k:
                self.result=root.val
                return

            traversal(root.right)
        traversal(root)
        return self.result 

# Complexity Analysis
# Time complexity: O(H+k), where H is a tree height. This complexity is defined by the stack, which contains at least H+k elements, since before starting to pop out one has to go down to a leaf. This results in O(logN+k) for the balanced tree and O(N+k) for a completely unbalanced tree with all the nodes in the left subtree.
# Space complexity: O(H) to keep the stack, where H is a tree height. That makes O(N) in the worst case of the skewed tree, and O(logN) in the average case of the balanced tree.

# Follow up: https://leetcode.com/problems/kth-smallest-element-in-a-bst/editorial/