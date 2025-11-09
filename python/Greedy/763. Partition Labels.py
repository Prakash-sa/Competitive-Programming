# https://leetcode.com/problems/partition-labels/description/

'''
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
Return a list of integers representing the size of these parts.

Example 1:
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:
Input: s = "eccbbbbdec"
Output: [10]

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
'''

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ans=[]
        mp=[-1]*26
        for i in range(len(s)):
            k=ord(s[i])-ord('a')
            mp[k]=i
        i=0
        while i<len(s):
            k=ord(s[i])-ord('a')
            j=mp[k]
            far=i+1
            while far<j+1:
                k=ord(s[far])-ord('a')
                j=max(j,mp[k])
                far+=1
            ans.append(j-i+1)
            i=j+1
        return ans


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ans=[]
        mp=[-1]*26
        for i in range(len(s)):
            k=ord(s[i])-ord('a')
            mp[k]=i
        start=end=0
        for i in range(len(s)):
            end=max(end,mp[ord(s[i])-ord('a')])
            if i==end:
                ans.append(end-start+1)
                start=end+1
        return ans

    


