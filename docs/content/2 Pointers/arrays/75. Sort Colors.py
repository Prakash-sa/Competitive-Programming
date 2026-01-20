# https://leetcode.com/problems/sort-colors/description/

#  Dutch National Flag Problem 

'''
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2] 

Constraints:
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
'''

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left,mid,right=0,0,len(nums)-1

        while mid<=right:
            if nums[mid]==0:
                nums[left],nums[mid]=nums[mid],nums[left]
                left+=1
                mid+=1
            elif nums[mid]==2:
                nums[mid],nums[right]=nums[right],nums[mid]
                right-=1
            else :
                mid+=1
            

# Complexity Analysis
# Time complexity : O(N) since it's one pass along the array of length N.
# Space complexity : O(1) since it's a constant space solution.
