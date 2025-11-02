# https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/



class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowel=set("aeiou")
        cur=sum(1 for i in range(min(k,len(s))) if s[i] in vowel)
        ans=cur
        for r in range(k,len(s)):
            if s[r] in vowel:
                cur+=1
            if s[r-k] in vowel:
                cur-=1
            
            if cur>ans:
                ans=cur

            if ans==k:
                return k

        return ans

        