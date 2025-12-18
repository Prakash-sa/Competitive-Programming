# https://leetcode.com/problems/find-the-duplicate-number/description/
# Video https://www.youtube.com/watch?v=wjYnzkAhcNk

'''
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
Example 3:
Input: nums = [3,3,3,3,3]
Output: 3
 

Constraints:
1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 
Follow up:
How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?
'''

from collections import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow=fast=nums[0]
        while True:
            fast=nums[nums[fast]]
            slow=nums[slow]
            if slow==fast:
                break

        slow=nums[0]
        while slow!=fast:
            slow=nums[slow]
            fast=nums[fast]

        return fast

# Complexity Analysis
# Time Complexity: O(n)
# Space Complexity: O(1)

# For a detailed analysis, please refer to Linked List Cycle II.