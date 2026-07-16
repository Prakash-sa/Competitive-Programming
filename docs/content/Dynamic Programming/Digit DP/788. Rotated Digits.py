# https://leetcode.com/problems/rotated-digits/description/

'''
An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
Example 2:

Input: n = 1
Output: 0
Example 3:

Input: n = 2
Output: 1
 

Constraints:

1 <= n <= 104
'''

class Solution:
    def digitDP(self,i,tight,changed):
        if i==len(self.A):
            return int(changed)
        ans=0
        limit=self.A[i] if tight else 9
        for d in range(limit+1):
            if d in {3,4,7}:
                continue
            next_tight=tight and (d==limit)
            next_change=changed or d in {2,5,6,9}
            ans+=self.digitDP(i+1,next_tight,next_change)
        return ans

    def rotatedDigits(self, n: int) -> int:
        self.A=list(map(int,str(n)))
        return self.digitDP(0,True,False)

'''
Complexity Analysis

Time Complexity: O(logN). We do constant-time work for each digit of N.

Space Complexity: O(logN), the space stored by memo.
'''