# https://leetcode.com/problems/permutations/description/

'''
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
 

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
'''

class Solution:
    def backtrack(self,nums,ind):
        if ind==len(nums):
            self.ans.append(nums[:])
            return
        for i in range(ind,len(nums)):
            nums[i],nums[ind]=nums[ind],nums[i]
            self.backtrack(nums,ind+1)
            nums[ind],nums[i]=nums[i],nums[ind]

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.ans=[]
        self.backtrack(nums,0)
        return self.ans

# Time Complexity: O(n*n!)
# Space Complexity: O(n)


