# https://leetcode.com/problems/top-k-frequent-elements/description/

'''
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
Example 3:
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]
Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
'''

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq=Counter(nums)
        h=[]

        for num in freq.keys():
            if len(h)<k or h[0][0]<freq[num]:
                heappush(h,(freq[num],num))
                if len(h)>k:
                    heappop(h)
        return [num for _,num in h]

# Complexity Analysis

# Time complexity : O(N+Nlogk) if k<N and O(1) in the particular case of N=k. That ensures time complexity to be better than O(NlogN).
# Space complexity : O(N+k) to store the hash map with not more N elements and a heap with k elements.


from collections import Counter

def topKFrequent(nums, k):
    freq = Counter(nums)
    buckets = [[] for _ in range(len(nums) + 1)]

    for num, count in freq.items():
        buckets[count].append(num)

    result = []
    for i in range(len(buckets) - 1, -1, -1):
        for num in buckets[i]:
            result.append(num)
            if len(result) == k:
                return result

# Bucket Sort
# O(n)
# Most optimal, when values are bounded by n
