# https://leetcode.com/problems/first-missing-positive/description/

'''
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

Constraints:
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
'''

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if not nums or 1 not in nums:
            return 1
        for i in range(len(nums)):
            if nums[i]<=0 or nums[i]>len(nums):
                nums[i]=1
        for num in nums:
            k=abs(num)-1
            if k>=0 and k<len(nums) and nums[k]>0:
                nums[k]=-1*nums[k]
        for i in range(len(nums)):
            if nums[i]>0:
                return i+1
        return len(nums)+1


# Complexity Analysis

# Time complexity: O(n)
# We loop through the elements in nums once, swapping elements to sort the array. Swapping takes constant time. Sorting nums using cycle sort takes O(n) time.
# Iterating through the sorted array and finding the first missing positive can take up to O(n).
# The total time complexity is O(2n), which simplifies to O(n).

# Space complexity: O(n)
# We modify the array nums and use it to determine the answer, so the space complexity is O(n).
# nums is the input array, so the auxiliary space used is O(1).