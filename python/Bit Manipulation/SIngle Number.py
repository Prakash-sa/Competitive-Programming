# Single Number 1

# https://leetcode.com/problems/single-number/description/

'''
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
'''

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        k=nums[0]
        for i in range(1,len(nums)):
            k^=nums[i]
        return k
        

# Time complexity : O(n). We only iterate through nums, so the time complexity is the number of elements in nums.
# Space complexity : O(1).

############################################
# Single Number 2

# https://leetcode.com/problems/single-number-ii/description/

'''
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99

Constraints:
1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
'''


