# https://leetcode.com/problems/subtree-of-another-tree/description/

'''
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

Constraints:
The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isMatch(self,root,subroot):
        if not (root and subroot):
            return root is subroot
        return (root.val==subroot.val) and self.isMatch(root.right,subroot.right) and self.isMatch(root.left,subroot.left)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if self.isMatch(root,subRoot):
            return True
        
        if not root:
            return False

        return self.isMatch(root.left,subRoot) or self.isMatch(root.right,subRoot)

# Naive approach, O(|s| * |t|)

class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        MOD_1=1000000007
        MOD_2=2147483647

        def hash_subtree_at_node(node,need_to_add):
            if node is None:
                return (3,7)
            
            left=hash_subtree_at_node(node.left,need_to_add)
            right=hash_subtree_at_node(node.right,need_to_add)

            left_1=(left[0]<<5)%MOD_1
            right_1=(right[0]<<1)%MOD_1

            left_2=(left[1]<<7)%MOD_2
            right_2=(right[1]<<1)%MOD_2

            hashpair=((left_1+right_1+node.val)%MOD_1,(left_2+right_2+node.val)%MOD_2)

            if need_to_add:
                memo.add(hashpair)
            return hashpair
        
        memo=set()

        hash_subtree_at_node(root,True)

        s=hash_subtree_at_node(subRoot,False)
        return s in memo

'''   
Complexity Analysis
Time complexity: O(M+N).
We are traversing the tree rooted at root in O(N) time. We are also traversing the tree rooted at subRoot in O(M) time. For each node, we are doing constant time operations. After traversing, for lookup we are either doing O(1) operations, or O(N) operations. Hence, the overall time complexity is O(N+M).

Space complexity: O(M+N).
We are using memo to store the hash pair of each node in the tree rooted at root. Hence, for this, we need O(N) space.
Moreover, since we are using recursion, the space required for the recursion stack will be O(N) for hashSubtreeAtNode(root, true) and O(M) for hashSubtreeAtNode(subRoot, false).
Hence, overall space complexity is O(M+N).
'''