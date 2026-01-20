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


# 

'''
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
'''

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res=[]

        def backtrack(index):
            if index==len(nums):
                res.append(nums[:])
                return
            used=set() # Track used values at current level
            for i in range(index,len(nums)):
                if nums[i] in used:
                    continue
                used.add(nums[i])
                nums[i],nums[index]=nums[index],nums[i]
                backtrack(index+1)
                nums[i],nums[index]=nums[index],nums[i]
        backtrack(0)
        return res
    

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        from collections import Counter
        res = []
        counter = Counter(nums)
        
        def backtrack(path):
            if len(path) == len(nums):
                res.append(path[:])
                return
            
            for num in counter:
                if counter[num] > 0:
                    path.append(num)
                    counter[num] -= 1
                    backtrack(path)
                    path.pop()
                    counter[num] += 1
        
        backtrack([])
        return res

# Time Compleixty:O(N*N!)

# Space Complexity:
# Swapping + used set per level	O(n²) (worst-case)	Due to used sets on recursion stack
# Counter + path	O(n)

# When you swap elements, the array gets rearranged, so checking nums[i] == nums[index] doesn't correctly identify all duplicate cases. You need to check for duplicates among the candidates at the current level, not just against the current index.

# 🐛 Example where it fails:
# Input: nums = [1, 1, 2]

# Your code might produce:

# [1, 1, 2]
# [1, 2, 1]
# [2, 1, 1]
# [2, 1, 1] ← duplicate!
