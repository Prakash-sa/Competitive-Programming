# https://leetcode.com/problems/koko-eating-bananas/description/

'''
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours
 

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:
1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
'''


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        def time_taken(rate):
            time=0
            for i in range(len(piles)):
                time+=ceil(piles[i]/rate)
            return time
        
        left,right=1,max(piles)
        while left<right:
            mid=(left+right)//2
            if time_taken(mid)>h:
                left=mid+1
            else:
                right=mid
        return left
        
# Time Complexity: O(log m * n) where m is the maximum number of apples on a tree and n is the number of trees in the apples array. Our binary search runs O(log m) times, and each time it runs it takes n operations to check how long it takes to collect all the apples for that rate.

# Space Complexity: O(1) We are using only a constant amount of space.