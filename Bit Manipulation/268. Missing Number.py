# https://leetcode.com/problems/missing-number/description/

'''
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]

Output: 2

Explanation:

n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]

Output: 8

Explanation:

n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

 
 

 

 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
'''

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        expected_sum=n*(n+1)//2
        actual_sum=0
        for i in range(n):
            actual_sum+=nums[i]
        return expected_sum-actual_sum

# Complexity Analysis

# Time complexity : O(n)
# Although Gauss' formula can be computed in O(1) time, summing nums
# costs us O(n) time, so the algorithm is overall linear. Because we have
# no information about which number is missing, an adversary could always
# design an input for which any algorithm that examines fewer than n
# numbers fails. Therefore, this solution is asymptotically optimal.

# Space complexity : O(1)
# This approach only pushes a few integers around, so it has constant
# memory usage.

