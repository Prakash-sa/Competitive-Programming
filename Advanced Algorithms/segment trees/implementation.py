'''
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
'''

from collections import List


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        def update(index,value,tree,size):
            index+=size
            tree[index]+=value
            while index>1:
                index//=2
                tree[index]=tree[index*2]+tree[index*2+1]

        def query(left,right,tree,size):
            result=0
            left+=size
            right+=size

            while left<right:
                if left%2==1:
                    result+=tree[left]
                    left+=1
                left//=2
                if right%2==1:
                    right-=1
                    result+=tree[right]
                right//=2
            return result

        offset=10**4
        size=2*10**4+1
        tree=[0]*(2*size)
        result=[]
        for num in reversed(nums):
            smaller_count=query(0,num+offset,tree,size)
            result.append(smaller_count)
            update(num+offset,1,tree,size)
        result.reverse()
        return result
        

# Complexity Analysis
# Let N be the length of nums and M be the difference between the maximum and minimum values in nums.
# Note that for convenience, we fix M=2∗10 4  in the above implementations.

# Time Complexity: O(Nlog(M)).
# We need to iterate over nums. For each element, we spend O(log(M)) to find the number of smaller elements after it, and spend O(log(M)) time to update the counts. In total, we need O(N⋅log(M))=O(Nlog(M)) time.

# Space Complexity: O(M), since we need, at most, an array of size 2M+2 to store the segment tree.
# We need at most M+1 buckets, where the extra 1 is for the value 0. For the segment tree, we need twice the number of buckets, which is (M+1)×2=2M+2.