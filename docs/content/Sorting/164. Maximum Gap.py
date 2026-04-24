# https://leetcode.com/problems/maximum-gap/description/

'''
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

Example 2:
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
 
Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
'''

class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums)<2:
            return 0
        nums.sort()
        ans=0
        for i in range(1,len(nums)):
            ans=max(ans,nums[i]-nums[i-1])
        return ans

# Time Complexity: O(nlog(n))



'''
Pigenhole O(n) solution

min, max, left n-2 elements
n-1 buckets

bucket size = ceil(max-min)/(n-1)=(49-3)/7=7

gap<bucket size
'''
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n=len(nums)
        if n<2:
            return 0

        lo,hi=min(nums),max(nums)

        if lo==hi:
            return 0
        
        
        b=math.ceil((hi-lo)/(n-1))
        k=(hi-lo)//b+1

        bucket_min=[float('inf')]*k
        bucket_max=[float('-inf')]*k
        used=[False]*k

        for x in nums:
            idx=(x-lo)//b
            bucket_min[idx]=min(bucket_min[idx],x)
            bucket_max[idx]=max(bucket_max[idx],x)
            used[idx]=True

        max_gap=0
        prev_max=None

        for i in range(k):
            if not used[i]:
                continue
            
            if prev_max is not None:
                max_gap=max(max_gap,bucket_min[i]-prev_max)
            prev_max=bucket_max[i]

        return max_gap
