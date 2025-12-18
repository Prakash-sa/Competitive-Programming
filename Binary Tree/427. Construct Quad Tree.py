# https://leetcode.com/problems/construct-quad-tree/description/

'''
Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.
Return the root of the Quad-Tree representing grid.
A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign the val to True or False when isLeaf is False, and both are accepted in the answer.
isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:
If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.
If you want to know more about the Quad-Tree, you can refer to the wiki.
Quad-Tree format:
You don't need to read this section for solving the problem. This is only if you want to understand the output format here. The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.
It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].
If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown below:
Notice that 0 represents False and 1 represents True in the photo representing the Quad-Tree.
Example 2:
Input: grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
Explanation: All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
Explanation is shown in the photo below.
 

Constraints:
n == grid.length == grid[i].length
n == 2x where 0 <= x <= 6
'''


"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        n=len(grid)
        S=[[0]*(n+1) for _ in range(n+1)]

        for i in range(n):
            row_sum=0
            for j in range(n):
                row_sum+=grid[i][j]
                S[i+1][j+1]=S[i][j+1]+row_sum
        
        def ones(r,c,length):
            r2,c2=r+length,c+length
            return S[r2][c2]-S[r][c2]-S[r2][c]+S[r][c]
        
        def build(r,c,length):
            total=ones(r,c,length)
            if total==0:
                return Node(False,True,None,None,None,None)
            if total==length*length:
                return Node(True,True,None,None,None,None)
            half=length//2
            tl=build(r,c,half)
            tr=build(r,c+half,half)
            bl=build(r+half,c,half)
            br=build(r+half,c+half,half)
            return Node(True,False,tl,tr,bl,br)
        return build(0,0,n)

    
# Approach: recursive divide-and-conquer with O(1) uniform checks via 2D prefix sums.
# Complexity: Time O(n^2). Space O(n^2) plus O(log n) stack.
# Result: Correct Quad-Tree with minimal rescans and optimal asymptotic cost.

