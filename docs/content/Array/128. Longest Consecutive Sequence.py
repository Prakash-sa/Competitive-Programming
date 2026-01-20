# https://leetcode.com/problems/longest-consecutive-sequence/description/

'''
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:
Input: nums = [1,0,1,2]
Output: 3

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
'''

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st=set(nums)
        ans=0

        for x in st:
            if x-1 not in st:
                y=x
                while y in st:
                    y+=1
                ans=max(ans,y-x)
        return ans

# Complexity
# Time: O(n) — each number is visited at most twice (once as potential start, once walking forward).
# Space: O(n) for the set.