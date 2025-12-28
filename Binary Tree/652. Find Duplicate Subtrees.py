# https://leetcode.com/problems/find-duplicate-subtrees/description/

'''
Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with the same node values.

Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:
Input: root = [2,1,1]
Output: [[1]]
Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]

Constraints:
The number of the nodes in the tree will be in the range [1, 5000]
-200 <= Node.val <= 200
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def dfs(self,root):
        if not root:
            return "null"
        s=",".join([str(root.val),self.dfs(root.left),self.dfs(root.right)])
        if len(self.subtree[s])==1:
            self.ans.append(root)
        self.subtree[s].append(root)

        return s



    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        self.subtree=defaultdict(list)
        self.ans=[]
        self.dfs(root)
        return self.ans



# Complexity Analysis
# Let n denote the number of nodes.

# Time complexity: O(n).
# We traverse the tree with n nodes and, for each subtree, find a triplet and an ID. We perform operations with the hash maps tripletToID and cnt. Since an ID is an integer and a triplet has a length of 3 (O(1)), these operations take O(1) time for each of the n nodes.

# Space complexity: O(n).
# We store the hash maps tripletToID and cnt, which take O(n) memory. Also, the recursion stack takes O(n) memory.

