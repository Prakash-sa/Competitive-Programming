# https://leetcode.com/problems/last-stone-weight/description/

'''
You are given an array of integers stones where stones[i] is the weight of the ith stone.
We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.
Return the weight of the last remaining stone. If there are no stones left, return 0.

Example 1:
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
Example 2:
Input: stones = [1]
Output: 1

Constraints:
1 <= stones.length <= 30
1 <= stones[i] <= 1000
'''

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones=[-stone for stone in stones]
        heapify(stones)

        while len(stones)>1:
            first=heappop(stones)
            second=heappop(stones)
            tmp=abs(first-second)
            if tmp>0:
                heappush(stones,-tmp)
        return -stones[0] if stones else 0


# Complexity Analysis
# Let N be the length of stones.
# Time complexity : O(NlogN).
# Converting an array into a Heap takes O(N) time (it isn't actually sorting; it's putting them into an order that allows us to get the maximums, each in O(logN) time).
# Like before, the main loop iterates up to N−1 times. This time however, it's doing up to three O(logN) operations each time; two removes, and an optional add. Like always, the three is an ignored constant. This means that we're doing N⋅O(logN)=O(NlogN) operations.

# Space complexity : O(N) or O(logN).
# In Python, heapq.heapify() is an in-place operation, so it uses O(1) auxiliary space. However, the heap still stores n elements within the input list, which contributes O(n) to total space complexity. So, the total space complexity is O(n).
# In Java though, it's O(N) to create the PriorityQueue.
# We could reduce the space complexity to O(1) by implementing our own iterative heapfiy, if needed.

