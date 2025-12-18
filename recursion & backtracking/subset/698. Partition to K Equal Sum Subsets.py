# https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
# https://www.youtube.com/watch?v=mBk4I0X46oI

'''
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:
Input: nums = [1,2,3,4], k = 3
Output: false

Constraints:
1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].
'''

class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total=sum(nums)
        if total%k:
            return False
        
        nums.sort(reverse=True)
        target=total//k
        n=len(nums)
        memo={}

        def dfs(used,curr_sum,count):
            if count==k-1:
                return True
            if (used,curr_sum) in memo:
                return memo[(used,curr_sum)]
            if curr_sum==target:
                res=dfs(used,0,count+1)
                memo[(used,curr_sum)]=res
                return res

            
            for i in range(n):
                if not (used>>i)&1 and curr_sum+nums[i]<=target:
                    if dfs(used|(1<<i),curr_sum+nums[i],count):
                        memo[(used,curr_sum)]=True
                        return True
                memo[(used,curr_sum)]=False
            return False
        
        return dfs(0,0,0)


# Approach: Backtracking + Bitmask + Memoization
# Time: O(n * 2^n)
# Space: O(2^n)
