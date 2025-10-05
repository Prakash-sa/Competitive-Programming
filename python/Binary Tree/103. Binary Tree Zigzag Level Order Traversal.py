# https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

'''
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from typing import Optional
from collections import deque,List

class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        ans=[]
        q=deque([root])
        while q:
            size=len(q)
            tmp=[]
            while size>0:
                size-=1
                k=q.popleft()
                tmp.append(k.val)
                if k.left:
                    q.append(k.left)
                if k.right:
                    q.append(k.right)
            ans.append(tmp)
        
        for i in range(len(ans)):
            if i%2:
                ans[i].reverse()
        return ans



# Complexity Analysis
# Time Complexity: O(N), where N is the number of nodes in the tree.
# Same as the previous BFS approach, we visit each node once and only once.

# Space Complexity: O(N).
# Unlike the BFS approach, in the DFS approach, we do not need to maintain the node_queue data structure for the traversal.
# However, the function recursion will incur additional memory consumption on the function call stack. As we can see, the size of the call stack for any invocation of DFS(node, level) will be exactly the number of level that the current node resides on. Therefore, the space complexity of our DFS algorithm is O(H), where H is the height of the tree. In the worst-case scenario, when the tree is very skewed, the tree height could be N. Thus the space complexity is also O(N).
# Note that if the tree were guaranteed to be balanced, then the maximum height of the tree would be logN which would result in a better space complexity than the BFS approach.
