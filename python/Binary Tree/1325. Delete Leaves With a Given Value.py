# https://leetcode.com/problems/delete-leaves-with-a-given-value/description/

'''
Given a binary tree root and an integer target, delete all the leaf nodes with value target.
Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

Example 1:
Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
Example 2:
Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]
Example 3:
Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.

Constraints:
The number of nodes in the tree is in the range [1, 3000].
1 <= Node.val, target <= 1000
'''



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        if not root:
            return None
        root.left=self.removeLeafNodes(root.left,target)
        root.right=self.removeLeafNodes(root.right,target)

        if root.val==target and not root.left and not root.right:
            return None

        return root

'''
Since deleting a child node might transform a parent node into a new leaf node, we should start checking and removing qualifying leaf nodes from the bottom of the tree. We will examine each level as we ascend the tree to ensure we identify all nodes requiring removal. This process of checking from the bottom to the top sets our traversal order.
Postorder traversal efficiently deletes targeted nodes in a binary tree by starting at the deepest leaves and moving upward. This ensures that each node is assessed for deletion only after its descendants, recursively capturing any new leaf nodes created by prior deletions. The process continues until the entire tree is covered, systematically eliminating all nodes with the target value.

Complexity Analysis
Let n be the number of nodes in the binary tree root.

Time Complexity: O(n)

Space Complexity: O(n)
'''