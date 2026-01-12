# https://leetcode.com/problems/stone-game-iii/description/

'''
Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.
The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.
The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.
Assume Alice and Bob play optimally.
Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

Example 1:
Input: stoneValue = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
Example 2:
Input: stoneValue = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.
Example 3:
Input: stoneValue = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.

Constraints:
1 <= stoneValue.length <= 5 * 104
-1000 <= stoneValue[i] <= 1000
'''



class Solution:

    not_computed = 10**9
    
    def _func(self,i,stoneValue):
        if i==self.n:
            return 0

        if self.dp[i] != self.not_computed:
            return self.dp[i]

        self.dp[i]=stoneValue[i]-self._func(i+1,stoneValue)
        if i+2<=self.n:
            self.dp[i]=max(self.dp[i],stoneValue[i]+stoneValue[i+1]-self._func(i+2,stoneValue))
        if i+3<=self.n:
            self.dp[i]=max(self.dp[i],stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-self._func(i+3,stoneValue))
        return self.dp[i]

    def stoneGameIII(self, stoneValue: List[int]) -> str:
        self.n=len(stoneValue)
        self.dp = [self.not_computed] * (self.n + 1)
        diff=self._func(0,stoneValue)
        if diff>0:
            return "Alice"
        if diff<0:
            return "Bob"
        return "Tie"


# Complexity Analysis
# Time complexity: O(n).
# Even though we changed the order of calculating DP, the time complexity is the same as in the previous approach: for each i, we compute dp[i] in O(1). Since we store the results in memory, we will calculate each dp[i] only once.

# Space complexity: O(n).