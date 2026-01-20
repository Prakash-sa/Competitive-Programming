# https://leetcode.com/problems/hand-of-straights/description/

'''
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

Example 1:
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

Constraints:
1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length
'''

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand)%groupSize:
            return False

        cnt=defaultdict(int)
        for i in range(len(hand)):
            cnt[hand[i]]+=1
        minH=list(cnt.keys())
        heapify(minH)
        while minH:
            first=minH[0]
            for i in range(first,first+groupSize):
                if i not in cnt:
                    return False
                cnt[i]-=1
                if cnt[i]==0:
                    if i==minH[0]:
                        heappop(minH)
                    else:
                        return False
        return True


# Complexity Analysis
# Let n be the size of the hand array and k be groupSize.
# Time complexity: O(n)

# Space complexity: O(n)
# The cardCount map stores the count of each card value.
# In the worst case, all cards could have distinct values, resulting in a map size of n.
# Therefore, the space complexity is O(n).
