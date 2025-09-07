## Jump Game 1

# https://leetcode.com/problems/jump-game/description/

'''
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
 
Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 
Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 105
'''

class Solution:
    def canJump(self,nums: List[int])->bool:
        goal=len(nums)-1
        for i in range(len(nums)-1):
            if i+nums[i]>=goal:
                goal=i
        return goal==0
    

# Complexity Analysis
# Time complexity : O(n).
# We are doing a single pass through the nums array, hence n steps, where n is the length of array nums.
# Space complexity : O(1).
# We are not using any extra memory.


#################################################
## Jump Game 2

# https://leetcode.com/problems/jump-game-ii/

'''
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
'''

class Solution:
    def jump(self, nums: List[int]) -> int:
        answer,n=0,len(nums)
        cur_end,cur_far=0,0

        for i in range(n-1):
            cur_far=max(cur_far,i+nums[i])

            if i==cur_end:
                answer+=1
                cur_end=cur_far

        return answer

# Complexity Analysis
# Time complexity: O(n)
# Space complexity: O(1)


#################################################
## Jump Game 3

# https://leetcode.com/problems/jump-game-iii/description/

'''
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.
Notice that you can not jump outside of the array at any time.


Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 

Example 2:
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3

Example 3:
Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.

Constraints:

1 <= arr.length <= 5 * 104
0 <= arr[i] < arr.length
0 <= start < arr.length
'''

# bfs

class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n=len(arr)
        q=deque([start])
        vis=[False]*n

        while q:
            node=q.popleft()

            if arr[node]==0:
                return True

            if vis[node]:
                continue
            vis[node]=True
            
            for i in [node+arr[node],node-arr[node]]:
                if 0<=i<n:
                    q.append(i)

        return False


# Complexity Analysis
# Time complexity: O(N) 
# Space complexity : O(N) 


# dfs
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if 0<=start<len(arr) and arr[start]>=0:
            if arr[start]==0:
                return True
            arr[start]=-arr[start]

            return self.canReach(arr,start+arr[start]) or self.canReach(arr,start-arr[start])
        return False
        




#################################################
## Jump Game 4

# https://leetcode.com/problems/jump-game-iii/description/

