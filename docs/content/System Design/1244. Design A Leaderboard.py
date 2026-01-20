# https://leetcode.com/problems/design-a-leaderboard/

'''
Design a Leaderboard class, which has 3 functions:
addScore(playerId, score): Update the leaderboard by adding score to the given player's score. If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
top(K): Return the score sum of the top K players.
reset(playerId): Reset the score of the player with the given id to 0 (in other words erase it from the leaderboard). It is guaranteed that the player was added to the leaderboard before calling this function.
Initially, the leaderboard is empty.

Example 1:
Input: 
["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
Output: 
[null,null,null,null,null,null,73,null,null,null,141]

Explanation: 
Leaderboard leaderboard = new Leaderboard ();
leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
leaderboard.top(1);           // returns 73;
leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
leaderboard.top(3);           // returns 141 = 51 + 51 + 39;

Constraints:
1 <= playerId, K <= 10000
It's guaranteed that K is less than or equal to the current number of players.
1 <= score <= 100
There will be at most 1000 function calls.
'''


class Leaderboard:
    def __init__(self):
        self.scores=defaultdict(int)
        
    def addScore(self, playerId: int, score: int) -> None:
        self.scores[playerId]+=score

    def top(self, K: int) -> int:
        return sum(heapq.nlargest(K,self.scores.values()))
        
    def reset(self, playerId: int) -> None:
        del self.scores[playerId]

# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)

class Leaderboard:

    def __init__(self):
        self.leaderboard=defaultdict(int)
        

    def addScore(self, playerId: int, score: int) -> None:
        self.leaderboard[playerId]=self.leaderboard.get(playerId,0)+score

    def top(self, K: int) -> int:
        arr=[]
        for k,v in self.leaderboard.items():
            heapq.heappush(arr,v)
            if len(arr)>K:
                heapq.heappop(arr)
        return sum(arr)
        

    def reset(self, playerId: int) -> None:
        del self.leaderboard[playerId]
        


# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)

from sortedcontainers import SortedList
from collections import defaultdict

class Leaderboard:
    def __init__(self):
        self.scores = defaultdict(int)   # playerId -> score
        self.sorted_scores = SortedList()  # sorted list of all scores

    def addScore(self, playerId: int, score: int) -> None:
        old = self.scores[playerId]
        if old != 0:
            self.sorted_scores.remove(old)
        new = old + score
        self.scores[playerId] = new
        self.sorted_scores.add(new)

    def top(self, K: int) -> int:
        # take last K elements (largest) and sum
        return sum(self.sorted_scores[-K:])

    def reset(self, playerId: int) -> None:
        old = self.scores[playerId]
        if old != 0:
            self.sorted_scores.remove(old)
        self.scores[playerId] = 0

'''

Still O(1) add, O(N log K) top, O(1) reset — but uses heappushpop and avoids extra work.

2) Better for frequent top(K) (uses a sorted structure)
If you can use a library, this makes:
addScore: O(log N)
reset: O(log N)
top(K): O(K) (no full scan)
'''


# Which one should you use?
# If this is LeetCode 1244 (no external libs): use Option 1.
# If this is real code and top() is called a lot: Option 2 is genuinely “better”.
