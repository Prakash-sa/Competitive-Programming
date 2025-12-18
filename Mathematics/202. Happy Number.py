# https://leetcode.com/problems/happy-number/description/

'''
Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:
Input: n = 2
Output: false

Constraints:
1 <= n <= 231 - 1
'''

class Solution:
    def isHappy(self, n: int) -> bool:
        
        vis=set()

        def square(num):
            res=0
            while num:
                k=num%10
                num//=10
                res+=k*k
            return res

        while True:
            vis.add(n)
            n=square(n)
            if n==1:
                return True
            if n in vis:
                return False
            vis.add(n)

        return False


'''
Complexity Analysis
Time complexity : O(243⋅3+logn+loglogn+logloglogn)... = O(logn).
Finding the next value for a given number has a cost of O(logn) because we are processing each digit in the number, and the number of digits in a number is given by logn.

Space complexity : O(logn).
Closely related to the time complexity, and is a measure of what numbers we're putting in the HashSet, and how big they are. For a large enough n, the most space will be taken by n itself.
'''
        
class Solution:
    def isHappy(self, n: int) -> bool:

        def square(num):
            res=0
            while num:
                k=num%10
                num//=10
                res+=k*k
            return res

        fast=slow=n
        while fast!=1 and square(fast)!=1:
            slow=square(slow)
            fast=square(square(fast))
            if fast==slow:
                return False

        return True

        
'''
Approach 2: Floyd's Cycle-Finding Algorithm
Complexity Analysis
Time complexity : O(logn). Builds on the analysis for the previous approach, except this time we need to analyse how much extra work is done by keeping track of two places instead of one, and how many times they'll need to go around the cycle before meeting.
If there is no cycle, then the fast runner will get to 1, and the slow runner will get halfway to 1. Because there were 2 runners instead of 1, we know that at worst, the cost was O(2⋅logn)=O(logn).
Like above, we're treating the length of the chain to the cycle as insignificant compared to the cost of calculating the next value for the first n. Therefore, the only thing we need to do is show that the number of times the runners go back over previously seen numbers in the chain is constant.
Once both pointers are in the cycle (which will take constant time to happen) the fast runner will get one step closer to the slow runner at each cycle. Once the fast runner is one step behind the slow runner, they'll meet on the next step. Imagine there are k numbers in the cycle. If they started at k−1 places apart (which is the furthest apart they can start), then it will take k−1 steps for the fast runner to reach the slow runner, which again is constant for our purposes. Therefore, the dominating operation is still calculating the next value for the starting n, which is O(logn).

Space complexity : O(1). For this approach, we don't need a HashSet to detect the cycles. The pointers require constant extra space.

'''

