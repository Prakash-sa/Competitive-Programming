# https://leetcode.com/problems/number-of-provinces/description/

'''
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
'''

class Solution:

    def dfs(self,idx: int, isConnected: List[List[int]]):
        if self.is_visible[idx]:
            return
        self.is_visible[idx]=True

        for j in range(len(isConnected)):
            if isConnected[idx][j]==1 and not self.is_visible[j]:
                self.dfs(j,isConnected)



    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n=len(isConnected)
        self.is_visible=[False]*(n)

        ans=0
        for i in range(0,n):
            if not self.is_visible[i]:
                self.dfs(i,isConnected)
                ans+=1
        return ans


# Complexity Analysis:
# Time complexity: O(n^2)
# Space complexity: O(n)
