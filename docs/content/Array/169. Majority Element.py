# https://leetcode.com/problems/majority-element/description/

'''
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.

Follow-up: Could you solve the problem in linear time and in O(1) space?
'''

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res,count=0,0
        for num in nums:
            if count==0:
                res=num
            count+=1 if res==num else -1
        return res
    

# Boyer-Moore Voting Algorithm
# Intuition
# If we had some way of counting instances of the majority element as +1
# and instances of any other element as −1, summing them would make it
# obvious that the majority element is indeed the majority element.


# Complexity Analysis
# Time complexity : O(n)

# Boyer-Moore performs constant work exactly n times, so the algorithm
# runs in linear time.

# Space complexity : O(1)

# Boyer-Moore allocates only constant additional memory.