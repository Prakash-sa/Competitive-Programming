# https://leetcode.com/problems/find-k-closest-elements/description/

'''
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:
Input: arr = [1,1,2,3,4,5], k = 4, x = -1
Output: [1,1,2,3]

Constraints:
1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
'''

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n=len(arr)
        if k>=n:
            return arr[:]
        
        l,r=0,n-k
        while l<r:
            mid=(l+r)//2

            if x-arr[mid]>arr[mid+k]-x:
                l=mid+1
            else:
                r=mid
        return arr[l:l+k]


# Time O(log(n − k)) for the binary search. Slicing the final window is O(k).
# Space O(1) extra.
