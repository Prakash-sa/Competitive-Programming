# https://leetcode.com/problems/binary-tree-right-side-view/description/

'''
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Explanation:

Example 2:
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]
Explanation:

Example 3:
Input: root = [1,null,3]
Output: [1,3]

Example 4:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        ans=[]
        queue=deque([root])

        while queue:
            s=len(queue)
            last=-1
            while s>0:
                s-=1
                q=queue.popleft()
                last=q.val
                if q.left:
                    queue.append(q.left)
                if q.right:
                    queue.append(q.right)
            ans.append(last)
        return ans


def rightmostNode(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        nodes = []
        queue = deque([root])

        while queue:
            level_size = len(queue)
            for i in range(level_size):
                node = queue.popleft()

                # current node is the rightmost node
                if i == level_size - 1:
                    nodes.append(node.val)

                # add nodes as normal to the queue
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        return nodes

# Complexity Analysis
# Time complexity: O(N) since one has to visit each node.
# Space complexity: O(D) to keep the queues, where D is a tree diameter. 
