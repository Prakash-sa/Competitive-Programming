# https://leetcode.com/problems/burst-balloons/description/

'''
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
'''

class Solution:

    def dfs(self,l,r,nums):
        if l>r:
            return 0
        if (l,r) in self.dp:
            return self.dp[(l,r)]
        self.dp[(l,r)]=0
        for i in range(l,r+1):
            gain=nums[l-1]*nums[i]*nums[r+1]
            remaining=self.dfs(l,i-1,nums)+self.dfs(i+1,r,nums)
            self.dp[(l,r)]=max(self.dp[(l,r)],gain+remaining)
        return self.dp[(l,r)]

    def maxCoins(self, nums: List[int]) -> int:
        nums=[1]+nums+[1]
        self.dp={}

        return self.dfs(1,len(nums)-2,nums)

        
# Complexity Analysis

# Let N be the number of balloons given.

# Time complexity: O(N3). 
# There are O(N2) states. For each state, determining the maximum coins requires iterating over all balloons in the range [left, right]. Thus the total time complexity is O(N2)×O(N)=O(N3).

# Space complexity: O(N2). We need O(N2) to store all states, O(N) for stacks to perform recursion, and O(N) to store [1] + nums + [1]. In total, this algorithm requires O(N 2)+O(N)+O(N)=O(N 2) space.  