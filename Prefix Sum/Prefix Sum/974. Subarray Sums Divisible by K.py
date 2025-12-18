# https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

'''
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:
Input: nums = [5], k = 9
Output: 0

Constraints:
1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104
'''

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        res=0
        pre=0
        count=[1]+[0]*k
        for num in nums:
            pre=(pre+num)%k
            res+=count[pre]
            count[pre]+=1
        return res

        
# Complexity Analysis
# Here, n is the length of nums and k is the given integer.

# Time complexity: O(n+k)
# We require O(k) time to initialize the modGroups array.

# Space complexity: O(k)
# We require O(k) space for the modGroups array.
