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
        
'''
Given a set of keys S = [S1 ,S2, …Sn], find the longest common prefix among a string q and S. This LCP query will be called frequently.

We could optimize LCP queries by storing the set of keys S in a Trie. For more information about Trie, please see this article Implement a trie (Prefix trie). In a Trie, each node descending from the root represents a common prefix of some keys. But we need to find the longest common prefix of a string q and all key strings. This means that we have to find the deepest path from the root, which satisfies the following conditions:

it is prefix of query string q
each node along the path must contain only one child element. Otherwise the found path will not be a common prefix among all strings.
the path doesn't comprise of nodes which are marked as end of key. Otherwise the path couldn't be a prefix a of key which is shorter than itself.
'''

## Trie Solution

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


# Complexity Analysis
# In the worst case query q has length m and it is equal to all n strings of the array.
# Time complexity : preprocessing O(S), where S is the number of all characters in the array, LCP query O(m).
# Trie build has O(S) time complexity. To find the common prefix of q in the Trie takes in the worst case O(m).

# Space complexity : O(S). We only used additional S extra space for the Trie.
