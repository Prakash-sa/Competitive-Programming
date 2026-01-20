# https://leetcode.com/problems/majority-element-ii/description/

'''
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]
Example 2:
Input: nums = [1]
Output: [1]
Example 3:
Input: nums = [1,2]
Output: [1,2]

Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 
Follow up: Could you solve the problem in linear time and in O(1) space?
'''

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        count1,count2=0,0
        cnt1,cnt2=None,None

        for num in nums:
            if num==cnt1:
                count1+=1
            elif num==cnt2:
                count2+=1
            elif count1==0:
                cnt1=num
                count1+=1
            elif count2==0:
                cnt2=num
                count2+=1
            else:
                count1-=1
                count2-=1
        
        res=[]
        for cnt in [cnt1,cnt2]:
            if cnt is not None and nums.count(cnt)>len(nums)//3:
                res.append(cnt)
        return res


# Boyer-Moore Voting Algorithm
# Complexity Analysis
# Time complexity : O(N) where N is the size of nums. We first go through nums looking for first and second potential candidates. We then count the number of occurrences for these two potential candidates in nums. Therefore, our runtime is O(N)+O(N)=O(2N)≈O(N).
# Space complexity : O(1) since we only have four variables for holding two potential candidates and two counters. Even the returning array is at most 2 elements.

