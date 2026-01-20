# https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

'''
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        def rserialize(root,vals):
            if root is None:
                vals.append('None')
            else:
                vals.append(str(root.val))
                rserialize(root.left,vals)
                rserialize(root.right,vals)
        vals=[]
        rserialize(root,vals)
        return ','.join(vals)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        def rdeserialize(vals):
            val=vals.pop(0)
            if val=='None':
                return None
            root=TreeNode(int(val))
            root.left=rdeserialize(vals)
            root.right=rdeserialize(vals)
            return root
        return rdeserialize(data.split(','))
        


# Serialize: O(n) time/space with list accumulation
# Deserialize: O(n²) worst-case due to pop(0), but acceptable for n ≤ 10⁴
# No exponential copying → no runtime error



# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        def dfs(root):
            if root is None:
                return ['None']
            return [str(root.val)]+dfs(root.left)+dfs(root.right)
        return ','.join(dfs(root))

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        vals=deque(data.split(','))
        def dfs():
            val=vals.popleft()
            if val=='None':
                return None
            node=TreeNode(int(val))
            node.left=dfs()
            node.right=dfs()
            return node

        return dfs()
        
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))


'''

Aspect:     	Your Previous Version	      This Version
Serialize:	    Used mutable list (good)	  Same logic, cleaner
Deserialize:	list.pop(0) → O(n) per call	  deque.popleft() → O(1)
Time Complexity:   O(n²) worst-case	          O(n)
Readability:	   Good	                      More idiomatic

'''