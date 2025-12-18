# https://leetcode.com/problems/counting-bits/description/

'''
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
 
Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

Constraints:
0 <= n <= 105

Follow up:
It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
'''

# Approach 3: DP + Least Significant Bit

'''
Following the same principle of the previous approach, we can also have a transition function by playing with the least significant bit.
Let look at the relation between x and x
 =x/2
x=(1001011101)2
=(605)10
x 
 =(100101110)2
 =(302) 0
We can see that x   is differ than x by one bit, because x 
  can be considered as the result of removing the least significant bit of x.
Thus, we have the following transition function of pop count P(x):
P(x)=P(x/2)+(xmod2)
'''

class Solution:
    def countBits(self, n: int) -> List[int]:
        res=[0]*(n+1)

        for i in range(n+1):
            res[i]=res[i>>1]+(i&1)
        return res


# Time Complexity: O(n)
# Space Complexity: O(1)
