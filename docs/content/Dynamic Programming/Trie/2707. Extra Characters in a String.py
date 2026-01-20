# https://leetcode.com/problems/extra-characters-in-a-string/description/

'''
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.
Return the minimum number of extra characters left over if you break up s optimally.

Example 1:
Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:
Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.

Constraints:
1 <= s.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
dictionary[i] and s consists of only lowercase English letters
dictionary contains distinct words
'''

class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n,dictionary_set=len(s),set(dictionary)

        @cache
        def dp(start):
            if start==n:
                return 0
            ans=dp(start+1)+1
            for end in range(start,n):
                cur=s[start:end+1]
                if cur in dictionary_set:
                    ans=min(ans,dp(end+1))
            return ans
        
        return dp(0)


# Complexity Analysis
# Let N be the total characters in the string.
# Let M be the average length of the strings in dictionary.
# Let K be the length of the dictionary.

# Time complexity: O(N^3). There can be N+1 unique states of the dp method. In each state of dp, we iterate over end, which is O(N) iterations. In each of these iterations, we create a substring, which costs O(N). Hence, the overall cost of the dp method is O(N^3).
# Space complexity: O(N+M⋅K). The HashSet used to store the strings in the dictionary will incur a cost of O(M⋅K). Additionally, the dp method will consume stack space and traverse to a depth of N in the worst case scenario, resulting in a cost of O(N).




# Trie

class TrieNode:
    def __init__(self):
        self.children={}
        self.is_word=False

class Solution:
    def buildTrie(self,dictionary):
        root=TrieNode()
        for word in dictionary:
            node=root
            for char in word:
                if char not in node.children:
                    node.children[char]=TrieNode()
                node=node.children[char]
            node.is_word=True
        return root

    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n=len(s)
        root=self.buildTrie(dictionary)
        dp=[0]*(n+1)
        for start in range(n-1,-1,-1):
            dp[start]=dp[start+1]+1
            node=root
            for end in range(start,n):
                if s[end] not in node.children:
                    break
                node=node.children[s[end]]
                if node.is_word:
                    dp[start]=min(dp[start],dp[end+1])
        return dp[0]



# Complexity Analysis
# Let N be the total characters in the string.
# Let M be the average length of the strings in dictionary.
# Let K be the length of the dictionary.

# Time complexity: O(N^2+M⋅K). The two nested for loops that are being used for the dynamic programming operation cost O(N^2). Building the trie costs O(M⋅K).

# Space complexity: O(N+M⋅K). The Trie used to store the strings in dictionary will incur a cost of O(M⋅K). The dp array will incur a cost of O(N).
