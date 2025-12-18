# https://leetcode.com/problems/maximum-product-subarray/description/

'''
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

Constraints:
1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
'''

from collections import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_prod,min_prod=nums[0],nums[0]
        ans=nums[0]

        for i in range(1,len(nums)):
            if nums[i]<0:
                max_prod,min_prod=min_prod,max_prod
            max_prod=max(max_prod*nums[i],nums[i])
            min_prod=min(min_prod*nums[i],nums[i])
            ans=max(ans,max_prod)
        return ans

# Complexity Analysis

# Time complexity : O(N) where N is the size of nums. The algorithm achieves linear runtime since we are going through nums only once.

# Space complexity : O(1) since no additional space is consumed rather than variables which keep track of the maximum product so far, the minimum product so far, current variable, temp variable, and placeholder variable for the result.