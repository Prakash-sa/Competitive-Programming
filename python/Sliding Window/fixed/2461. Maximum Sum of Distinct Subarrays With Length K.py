# https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

'''
You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:
Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:
1 <= k <= nums.length <= 105
1 <= nums[i] <= 105
'''
from collections import defaultdict, List

class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        freq=defaultdict(int)
        n=len(nums)
        
        ans=0
        total=0
        for i in range(k):
            total+=nums[i]
            freq[nums[i]]+=1
        
        if len(freq)==k:
            ans=total
        
        for i in range(k,n):
            total+=nums[i]-nums[i-k]
            freq[nums[i]]+=1
            freq[nums[i-k]]-=1
            if freq[nums[i-k]]==0:
                del freq[nums[i-k]]
            if len(freq)==k:
                ans=max(ans,total)
        return ans

# Complexity Analysis
# Let N be the size of nums.

# Time Complexity: O(N)
# In the sliding window technique, in the worst case, our begin is adjusted for every increment of end . In total, adjusting begin takes O(N) time, resulting in an overall total time complexity is O(N)

# Space Complexity: O(N)
# The space complexity is O(N) due to the size of the numToIndex hash map.