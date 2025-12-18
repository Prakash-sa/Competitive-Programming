# https://leetcode.com/problems/combination-sum-iv/description/

'''
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:
Input: nums = [9], target = 3
Output: 0

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000

Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?
'''

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp=[0]*(target+1)

        dp[0]=1

        for i in range(1,target+1):
            for num in nums:
                if i>=num:
                    dp[i]+=dp[i-num]
        return dp[target]
        

'''
If swap the loops:
Your current approach is solving a different problem — specifically, it counts combinations (order doesn't matter), but the problem asks for permutations (order does matter).

Key Insight:
In Combination Sum IV, sequences like [1,2] and [2,1] are considered different.
Your current nested loop (for num in nums then for i from num to target) ensures that each number is used in a fixed order, which prevents counting permutations.
Correct Approach:
To count all permutations, you need to:

Iterate over each target sum from 1 to target (outer loop),
And for each sum, try every number in nums (inner loop).
This way, at every total i, you consider all possible last numbers that could have led to it, which naturally accounts for different orders.
'''

# Time Complexity: O(N*Target)
# Space Complexity: O(Target)