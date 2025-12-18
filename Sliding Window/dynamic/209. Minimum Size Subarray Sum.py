# https://leetcode.com/problems/minimum-size-subarray-sum/description/

'''
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

Constraints:
1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
'''

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n=len(nums)
        l=0
        cur=0
        ans=n+1

        for i,val in enumerate(nums):
            cur+=val
            while cur>=target:
                window_len=i-l+1
                if window_len<ans:
                    ans=window_len
                cur-=nums[l]
                l+=1
        return 0 if ans==n+1 else ans
    
# Approach sliding window with two pointers and running sum
# Time O(n). Space O(1)