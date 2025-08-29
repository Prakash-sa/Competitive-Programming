# https://leetcode.com/problems/longest-common-prefix/description/

'''
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty
'''

class Solution:
    
    def longestCommonPrefix(self,strs):
        
        if not strs:
            return ""
        
        prefix=strs[0]
        
        for word in strs[1:]:
            while not word.startswith(prefix):
                prefix=prefix[:-1]
                if not prefix:
                    return ""
        return prefix
        

class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEnd = False
        self.linkCount = 0

    def addChild(self, char):
        if char not in self.children:
            self.children[char] = TrieNode()
            self.linkCount += 1


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.addChild(char)
            node = node.children[char]
        node.isEnd = True

    def searchLongestPrefix(self, word):
        node = self.root
        chars = []
        for char in word:
            if char in node.children and node.linkCount == 1 and not node.isEnd:
                chars.append(char)
                node = node.children[char]
            else:
                break
        return "".join(chars)


class Solution:
    def longestCommonPrefix(self, q, strs):
        if not strs:
            return ""
        if len(strs) == 1:
            return strs[0]
        trie = Trie()
        for s in strs[1:]:
            trie.insert(s)
        return trie.searchLongestPrefix(q)