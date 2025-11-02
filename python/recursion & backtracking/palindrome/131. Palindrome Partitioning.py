# https://leetcode.com/problems/palindrome-partitioning/description/

'''
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:
Input: s = "a"
Output: [["a"]]

Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
'''

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        result=[]

        def isPalindrome(s):
            return s==s[::-1]
        
        def dfs(s,path,result):
            if not s:
                result.append(path)
            
            for i in range(1,len(s)+1):
                if isPalindrome(s[:i]):
                    dfs(s[i:],path+[s[:i]],result)
        dfs(s,[],result)
        return result

# Complexity Analysis
# Time Complexity : O(N⋅2^N), where N is the length of string s. This is the worst-case time complexity when all the possible substrings are palindrome.
# Space Complexity: O(N), where N is the length of the string s. This space will be used to store the recursion stack. For s = aaa, the maximum depth of the recursive call stack is 3 which is equivalent to N.
