# https://leetcode.com/problems/combination-sum-ii/description/

'''
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[[1,1,6],[1,2,5],[1,7],[2,6]]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[[1,2,2],[5]]

Constraints:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
'''

class Solution:
    def recursive(self,comb,candidates,target,start):
        if target==0:
            self.ans.append(comb[:])
            return
        for i in range(start,len(candidates)):
            if target-candidates[i]<0:
                continue
            if i>start and candidates[i-1]==candidates[i]:
                continue
            comb.append(candidates[i])
            self.recursive(comb[:],candidates,target-candidates[i],i+1)
            comb.pop()

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        self.ans=[]
        candidates.sort()
        self.recursive([],candidates,target,0)
        return self.ans


# Time complexity: O(2^N)
# Space complexity: O(N)