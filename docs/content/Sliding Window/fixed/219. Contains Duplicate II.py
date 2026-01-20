# https://leetcode.com/problems/contains-duplicate-ii/description/

'''
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
'''

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        freq=defaultdict(int)

        for i in range(len(nums)-1,-1,-1):
            if nums[i] not in freq:
                freq[nums[i]]=i
            else:
                if abs(freq[nums[i]]-i)<=k:
                    return True
                else:
                    freq[nums[i]]=i
            if len(freq)>k:
                del freq[nums[i+k]]
        return False

        
# Complexity Analysis

# Time complexity : O(n).
# We do n operations of search, delete and insert, each with constant time complexity.

# Space complexity : O(min(n,k)).
# The extra space required depends on the number of items stored in the hash table, which is the size of the sliding window, min(n,k).

