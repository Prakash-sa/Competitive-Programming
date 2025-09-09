# https://leetcode.com/problems/subsets/description/

'''
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
'''

## Cascading

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        output=[[]]

        for num in nums:
            newSubsets=[]
            for curr in output:
                temp=curr.copy()
                temp.append(num)
                newSubsets.append(temp)
            for curr in newSubsets:
                output.append(curr)

        return output

# Time Complexity: O(N*2^N)
# Space Complexity: O(N*2^N)

## Backtracking

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.output=[]
        self.n=len(nums)
        self.backtrack(0,[],nums)
        return self.output

    def backtrack(self,first,curr,nums):
        self.output.append(curr[:])
        for i in range(first,self.n):
            curr.append(nums[i])
            self.backtrack(i+1,curr,nums)
            curr.pop()

# Time Complexity: O(N*2^N)
# Space Complexity: O(N*2^N)

# Lexiographic Subsets

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        output=[]

        for i in range(2**n,2**(n+1)):
            bitmask=bin(i)[3:]
            output.append([nums[j] for j in range(n) if bitmask[j]=="1"])
        
        return output

# Time complexity: O(N×2^N)
# Space complexity: O(N)

for i in range(2**n, 2 ** (n + 1)):
    # generate bitmask, from 0..00 to 1..11
    bitmask = bin(i)[3:]


##########################################

# https://leetcode.com/problems/subsets-ii/description/

'''
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
 
Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
'''
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.output=[]
        self.n=len(nums)
        self.backtrack(0,[],nums)
        return self.output
    
    def backtrack(self,index,curr,nums):
        self.output.append(curr[:])

        for i in range(index,self.n):
            if i!=index and nums[i]==nums[i-1]:
                continue
            curr.append(nums[i])
            self.backtrack(i+1,curr,nums)
            curr.pop()
