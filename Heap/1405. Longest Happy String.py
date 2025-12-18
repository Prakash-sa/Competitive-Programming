# https://leetcode.com/problems/longest-happy-string/description/

'''
A string s is called happy if it satisfies the following conditions:
s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
 

Constraints:
0 <= a, b, c <= 100
a + b + c > 0
'''

import heapq

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        h=[]

        if a>0:
            heapq.heappush(h,(-a,'a'))
        if b>0:
            heapq.heappush(h,(-b,'b'))
        if c>0:
            heapq.heappush(h,(-c,'c'))
        
        res=[]
        while len(h):
            cnt,char=heapq.heappop(h)
            if len(res)>=2 and res[-1]==char and res[-2]==char:
                if not h:
                    break
                acnt,achar=heapq.heappop(h)
                res.append(achar)
                if acnt+1<0:
                    heapq.heappush(h,(acnt+1,achar))
                heapq.heappush(h,(cnt,char))
            else:
                cnt=-cnt
                tmp=cnt
                for _ in range(min(2,tmp)):
                    cnt-=1
                    res.append(char)
                if cnt>0:
                    heapq.heappush(h,(-cnt,char))
        return "".join(res)


# Complexity Analysis
# Time complexity: O(a+b+c)
# Each operation on the priority queue (insertion or removal) takes O(logk) time, where k is the number of distinct characters. In this case, k is equal to 3, so each heap operation takes O(log3), which simplifies to O(1) time.
# In each iteration, one character is either added to the result string or skipped, and there are a+b+c characters in total. Therefore, the total number of iterations is proportional to a+b+c.
# Thus, the overall time complexity is O(a+b+c).

# Space complexity: O(1)
# The space complexity is O(1), as the heap contains at most three elements and the result string uses O(a+b+c) space (not counted in the solution space).
