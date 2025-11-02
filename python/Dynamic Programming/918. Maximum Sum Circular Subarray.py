# https://leetcode.com/problems/maximum-sum-circular-subarray/description/

'''
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:
Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:
Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.

Constraints:
n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
'''

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        total = 0
        max_ending = max_so_far = nums[0]
        min_ending = min_so_far = nums[0]
        total = nums[0]

        for x in nums[1:]:
            total += x
            # Kadane for max subarray
            max_ending = max(x, max_ending + x)
            max_so_far = max(max_so_far, max_ending)
            # Kadane for min subarray
            min_ending = min(x, min_ending + x)
            min_so_far = min(min_so_far, min_ending)

        # If all numbers are negative, max_so_far is the answer
        if max_so_far < 0:    # equivalently: total == min_so_far
            return max_so_far

        # Otherwise, choose best of non-wrap and wrap
        return max(max_so_far, total - min_so_far)
    

# Complexity Analysis
# Here, N is the length of the input array.
# Time complexity: O(N).
# The algorithm iterates over all elements to calculate the maxSum, minSum, and sum which takes O(N) time.
# Space complexity: O(1).
# The algorithm doesn't use extra space other than several integer variables.
