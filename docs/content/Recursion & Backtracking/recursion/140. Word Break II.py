# 

'''
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []

Constraints:
1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Input is generated in a way that the length of the answer doesn't exceed 105.
'''




class Solution:
    @cache
    def _backtrack(self,i):
        if i==len(self.s):
            return [""]
        res=[]
        for  j in range(i,len(self.s)):
            w=self.s[i:j+1]
            if w not in self.wordDict:
                continue
            arr_str=self._backtrack(j+1)
            if not arr_str:
                continue
            for string in arr_str:
                sentence=w
                if string:
                    sentence+=" "+string
                res.append(sentence)
        return res

    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        self.wordDict=set(wordDict)
        self.s=s
        return self._backtrack(0)
    
# Complexity Analysis
# Let n be the length of the input string.

# Time complexity: O(n⋅2 n)
# While memoization avoids redundant computations, it does not change the overall number of subproblems that need to be solved. In the worst case, there are still unique 2n possible substrings that need to be explored, leading to an exponential time complexity. For each subproblem, O(n) work is performed, so the overall complexity is O(n⋅2 n).

# Space complexity: O(n⋅2 n)

# The recursion stack can grow up to a depth of n, where each recursive call consumes additional space for storing the current state.
# The memoization map needs to store the results for all possible substrings, which can be up to 2 n substrings of size n in the worst case, resulting in an exponential space complexity.

