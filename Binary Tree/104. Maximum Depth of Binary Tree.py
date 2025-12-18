# https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

'''
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:
Input: root = [1,null,2]
Output: 2

Constraints:
The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
'''

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def dfs(root:Optional[TreeNode])->int:
            if not root:
                return 0

            l=dfs(root.left)
            r=dfs(root.right)
            return max(l,r)+1

        return dfs(root)


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        stack=[]
        stack.append((1,root))
        dep=0
        while stack:
            curr_dep,root=stack.pop()
            if not root:
                continue
            dep=max(dep,curr_dep)
            stack.append((curr_dep+1,root.left))
            stack.append((curr_dep+1,root.right))
        return dep


# Complexity analysis

# Time complexity: O(N).

# Space complexity: in the worst case, the tree is completely unbalanced, e.g. each node has only the left child node, the recursion call would occur N times (the height of the tree), the storage to keep the call stack would be O(N). But in the average case (the tree is balanced), the height of the tree would be log(N). Therefore, the space complexity in this case would be O(log(N)).


        