# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

'''
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        preorder_index=0
        inorder_map={}

        def array_to_tree(left,right):
            nonlocal preorder_index
            if left>right:
                return None
            
            root_val=preorder[preorder_index]
            root=TreeNode(root_val)

            preorder_index+=1
            root.left=array_to_tree(left,inorder_map[root_val]-1)
            root.right=array_to_tree(inorder_map[root_val]+1,right)
            return root



        for i in range(len(inorder)):
            inorder_map[inorder[i]]=i
        
        return array_to_tree(0,len(preorder)-1)
    
'''
Complexity analysis
Let N be the length of the input arrays.
Time complexity : O(N).
Building the hashmap takes O(N) time, as there are N nodes to add, and adding items to a hashmap has a cost of O(1), so we get N⋅O(1)=O(N).
Building the tree also takes O(N) time. The recursive helper method has a cost of O(1) for each call (it has no loops), and it is called once for each of the N nodes, giving a total of O(N).
Taking both into consideration, the time complexity is O(N).

Space complexity : O(N).
Building the hashmap and storing the entire tree each requires O(N) memory. The size of the implicit system stack used by recursion calls depends on the height of the tree, which is O(N) in the worst case and O(logN) on average. Taking both into consideration, the space complexity is O(N).

The two key observations are:

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/Figures/105/105-Page-2_fix.jpg

Preorder traversal follows Root -> Left -> Right, therefore, given the preorder array preorder, we have easy access to the root which is preorder[0].

Inorder traversal follows Left -> Root -> Right, therefore if we know the position of Root, we can recursively split the entire array into two subtrees.
'''

