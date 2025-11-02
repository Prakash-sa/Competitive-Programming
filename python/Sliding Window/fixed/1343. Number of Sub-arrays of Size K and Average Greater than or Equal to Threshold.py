# https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/

'''
Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

Example 1:

Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
Example 2:

Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
'''


class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        
        target=threshold*k

        window_sum=sum(arr[:k])
        ans=1 if window_sum>=target else 0

        for i in range(k,len(arr)):
            window_sum+=arr[i]
            window_sum-=arr[i-k]
            ans+=1 if window_sum>=target else 0
        return ans
