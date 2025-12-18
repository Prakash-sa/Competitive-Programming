# https://leetcode.com/problems/delete-node-in-a-bst/description/

'''
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node. 

Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:
Input: root = [], key = 0
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105

Follow up: Could you solve it with time complexity O(height of tree)?
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return None
        
        if key<root.val:
            root.left=self.deleteNode(root.left,key)
            return root
        if key>root.val:
            root.right=self.deleteNode(root.right,key)
            return root
        if not root.left:
            return root.right
        if not root.right:
            return root.left

        def successor(root):
            root=root.right
            while root.left:
                root=root.left
            return root.val
        
        def predecessor(root):
            root=root.left
            while root.right:
                root=root.right
            return root.val
        
        if not root.left and not root.right:
            return None
        elif root.right:
            root.val=successor(root)
            root.right=self.deleteNode(root.right,root.val)
        else:
            root.val=predecessor(root)
            root.left=self.deleteNode(root.left,root.val)
        return root
        
        return root
    



'''
Key Learnings for me:

First find the node that we need to delete.
After it's found, think about ways to keep the tree BST after deleting the node.
If there's no left or right subtree, we found the leaf. Delete this node without any further traversing.
If it's not a leaf node, what node we can use from the subtree that can replace the delete node and still maintain the BST property? We can either replace the delete node with the minimum from the right subtree (if right exists) or we can replace the delete node with the maximum from the left subtree (if left exists).
'''

# Time Complexity
# Average Case (Balanced BST): O(log n)

# Each recursive call goes one level deeper in the tree
# Finding successor/predecessor takes O(log n) in balanced tree
# Total: O(log n) for search + O(log n) for successor/predecessor = O(log n)
# Worst Case (Skewed Tree): O(n)

# Tree degenerates to a linked list
# Both search and successor/predecessor finding take O(n)
# Space Complexity
# Average Case: O(log n)

# Recursion stack depth equals tree height
# Worst Case: O(n)

# Skewed tree leads to n recursive calls on the stack