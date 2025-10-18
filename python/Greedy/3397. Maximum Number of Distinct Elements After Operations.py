# https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/

'''
You are given an integer array nums and an integer k.
You are allowed to perform the following operation on each element of the array at most once:
Add an integer in the range [-k, k] to the element.
Return the maximum possible number of distinct elements in nums after performing the operations.

Example 1:
Input: nums = [1,2,2,3,3,4], k = 2
Output: 6
Explanation:
nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the first four elements.

Example 2:
Input: nums = [4,4,4,4], k = 1
Output: 3
Explanation:
By adding -1 to nums[0] and 1 to nums[1], nums changes to [3, 5, 4, 4].

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= k <= 109
'''
class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        next_min=-inf
        count=0

        for tmp in nums:
            candidate=max(tmp-k,next_min)

            if candidate<=tmp+k:
                count+=1
                next_min=candidate+1
        return count        


# Complexity Analysis
# Let n be the length of the given array nums.

# Time complexity: O(nlogn).

# Sorting takes O(nlogn) time, and traversing the array once after sorting takes O(n) time, resulting in a total of O(nlogn).

# Space complexity: O(logn).

# The recursive stack space used by the sorting algorithm is O(logn).


