# https://leetcode.com/problems/binary-tree-level-order-traversal/description/

'''
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:
Input: root = [1]
Output: [[1]]
Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q=deque([root])
        ans=[]
        if not root:
            return ans

        while len(q)>0:
            size=len(q)
            tmp=[]
            for _ in range(size):
                tq=q.popleft()
                tmp.append(tq.val)
                if tq.left:
                    q.append(tq.left)
                if tq.right:
                    q.append(tq.right)

            ans.append(tmp)
        return ans


# Complexity Analysis
# Time complexity: O(N) since each node is processed exactly once.
# Space complexity: O(N) to keep the output structure which contains N node values.