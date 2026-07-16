# https://leetcode.com/problems/kth-largest-element-in-an-array/description/

'''
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting? 

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:
1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
'''

from heapq import heappush,heappop
from collections import List

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        h=[]
        for num in nums:
            if len(h)<k or h[0]<num:
                heappush(h,num)
                if len(h)>k:
                    heappop(h)
        return h[0]

# Comeplexity:
# Time: O(NlogK)
# Space: O(K)


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_value = min(nums)
        max_value = max(nums)
        count = [0] * (max_value - min_value + 1)

        for num in nums:
            count[num - min_value] += 1

        remain = k
        for num in range(len(count) - 1, -1, -1):
            remain -= count[num]
            if remain <= 0:
                return num + min_value

        return -1

'''
Complexity Analysis
Given n as the length of nums and m as maxValue - minValue,

Time complexity: O(n+m)
We first find maxValue and minValue, which costs O(n).
Next, we initialize count, which costs O(m).
Next, we populate count, which costs O(n).
Finally, we iterate over the indices of count, which costs up to O(m).

Space complexity: O(m)
We create an array count with size O(m).
'''
