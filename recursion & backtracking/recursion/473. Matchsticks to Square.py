# https://leetcode.com/problems/matchsticks-to-square/description/

'''
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
Return true if you can make this square and false otherwise.

Example 1:
Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.

Constraints:
1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108
'''

class Solution:
    sides=[]
    def backtrack(self,i,matchsticks,target):
        if i==len(matchsticks):
            return True
        
        for j in range(4):
            if self.sides[j]+matchsticks[i]<=target:
                self.sides[j]+=matchsticks[i]
                if self.backtrack(i+1,matchsticks,target):
                    return True
                self.sides[j]-=matchsticks[i]
        return False


    def makesquare(self, matchsticks: List[int]) -> bool:
        s=sum(matchsticks)
        self.sides=[0]*4
        if s%4!=0:
            return False
        target=s//4

        matchsticks.sort(reverse=True)
        return self.backtrack(0,matchsticks,target)

# Complexity Analysis
# Time Complexity: O(4^N) because we have a total of N sticks and for each one of those matchsticks,
# we have 4 different possibilities for the subsets they might belong to or the side of the square they might be a part of.

# Space Complexity: O(N). For recursive solutions, the space complexity is the stack space occupied by all the recursive calls. 
# The deepest recursive call here would be of size N and hence the space complexity is O(N). There is no additional space other than the recursion stack in this solution.
