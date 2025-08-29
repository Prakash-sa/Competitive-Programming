# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

'''
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
'''
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def lower_bound(x:int):
            l,r=0,len(nums)

            while l<r:
                mid=(l+r)//2

                if nums[mid]<x:
                    l=mid+1
                else :
                    r=mid
            return l

        left=lower_bound(target)

        if left==len(nums) or nums[left]!=target:
            return [-1,-1]

        right=lower_bound(target+1)
        return [left,right-1]

        
# Time Complexity: O(logN) considering there are N elements in the array. This is because binary search takes logarithmic time to scan an array of N elements. Why? Because at each step we discard half of the array we are scanning and hence, we're done after a logarithmic number of steps. We simply perform binary search twice in this case.

# Space Complexity: O(1) since we only use space for a few variables and our result array, all of which require constant space.

