# https://leetcode.com/problems/reorganize-string/description/

'''
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

Example 1:
Input: s = "aab"
Output: "aba"
Example 2:
Input: s = "aaab"
Output: ""

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
'''


from heapq import heappush,heappop
class Solution:
    def reorganizeString(self, s: str) -> str:
        freq=Counter(s)
        h=[]

        for char,cnt in freq.items():
            heappush(h,(-cnt,char))
        
        res=[]
        while len(h):
            cnt,char=heappop(h)

            if len(res)>=1 and res[-1]==char:
                if not h:
                    break
                tcnt,tchar=heappop(h)
                res.append(tchar)
                if tcnt+1<0:
                    heappush(h,(tcnt+1,tchar))
                heappush(h,(cnt,char))
            else:
                res.append(char)
                if cnt+1<0:
                    heappush(h,(cnt+1,char))
        if len(res)!=len(s):
            return ""
        return "".join(res)

# Complexity Analysis
# Let N be the total characters in the string.
# Let k be the total unique characters in the string.

# Time complexity: O(N⋅logk). We add one character to the string per iteration, so there are O(N) iterations. In each iteration, we perform a maximum of 3 priority queue operations. Each priority queue operation costs logk. For this problem, k is bounded by 26, so one could argue that the time complexity is actually O(N).

# Space complexity: O(k). The counter used to count the number of occurrences will incur a space complexity of O(k). Similarly, the maximum size of the priority queue will also be O(k). Given that k <= 26 in this problem, one could argue the space complexity is O(1).