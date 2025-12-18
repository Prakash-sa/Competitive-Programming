# https://leetcode.com/problems/longest-turbulent-subarray/description/

'''
Given an integer array arr, return the length of a maximum size turbulent subarray of arr.
A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:
For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.
 
Example 1:
Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
Example 2:
Input: arr = [4,8,12,16]
Output: 2
Example 3:
Input: arr = [100]
Output: 1

Constraints:
1 <= arr.length <= 4 * 104
0 <= arr[i] <= 109
'''

class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        n=len(arr)
        if n<=1:
            return n
        
        def sign(x):
            if x>0:
                return 1
            if x<0:
                return -1
            return 0
        
        ans=1
        curr=1
        prev=0

        for i in range(1,n):
            s=sign(arr[i]-arr[i-1])
            if s==0:
                curr=1
            elif i>1 and prev*s==-1:
                curr+=1
            else:
                curr=2
            ans=max(ans,curr)
            prev=s
        return ans


# Time O(n). Space O(1).
# Correct because the rule prev*s equals −1 captures exact alternation of signs. Equality resets. Starting new run at length 2 is minimal valid turbulent subarray when two adjacent differ.
