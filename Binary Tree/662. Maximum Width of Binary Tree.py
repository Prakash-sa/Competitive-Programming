# https://leetcode.com/problems/maximum-width-of-binary-tree/description/

'''
Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer. 

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 

Constraints:
The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from collections import deque
from typing import Optional

class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        q=deque([(root,0)])
        ans=0
        while q:
            size=len(q)
            _,level_head_idx=q[0]

            for _ in range(size):
                node,col_index=q.popleft()

                if node.left:
                    q.append((node.left,2*col_index))
                if node.right:
                    q.append((node.right,2*col_index+1))
            ans=max(ans,col_index-level_head_idx+1)

        return ans

        
# Complexity Analysis
# Let N be the total number of nodes in the input tree.
# Time Complexity: O(N).
# Similar to the BFS traversal, we visit each node once and only once in the DFS traversal. And each visit takes a constant time to process as well.
# Space Complexity: O(N)
# Unlike the BFS traversal, we used an additional table to keep the index for the first element per level. In the worst case where the tree is extremely skewed, there could be as many levels as the number of nodes. As a result, the space complexity of the table would be O(N).
# Since we implement DFS traversal with recursion which would incur some additional memory consumption in the function call stack, we need to take this into account for the space complexity.

