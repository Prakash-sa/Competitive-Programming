# https://leetcode.com/problems/word-search-ii/description/

'''
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
'''

class TrieNode:
    def __init__(self):
        self.children={}
        self.isWord=False
    
    def addWord(self,word):
        cur=self
        for c in word:
            if c not in cur.children:
                cur.children[c]=TrieNode()
            cur=cur.children[c]
        cur.isWord=True


class Solution:

    def dfs(self,r,c,node,word,board):
        if r<0 or c<0 or r==self.row or c==self.col or (r,c) in self.visit or board[r][c] not in node.children:
            return
        self.visit.add((r,c))
        node=node.children[board[r][c]]
        word+=board[r][c]
        if node.isWord:
            self.res.add(word)
        
        self.dfs(r-1,c,node,word,board)
        self.dfs(r,c-1,node,word,board)
        self.dfs(r+1,c,node,word,board)
        self.dfs(r,c+1,node,word,board)
        self.visit.remove((r,c))


    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root=TrieNode()
        for w in words:
            root.addWord(w)
        self.row,self.col=len(board),len(board[0])
        self.res,self.visit=set(),set()
        for r in range(self.row):
            for c in range(self.col):
                self.dfs(r,c,root,"",board)
        return list(self.res)

'''
Complexity
Time complexity: O(M(4⋅3^L−1 )), where M is the number of cells in the board and L is the maximum length of words.

It is tricky is calculate the exact number of steps that a backtracking algorithm would perform. We provide a upper bound of steps for the worst scenario for this problem. The algorithm loops over all the cells in the board, therefore we have M as a factor in the complexity formula. It then boils down to the maximum number of steps we would need for each starting cell (i.e.4⋅3 L−1 ).
Assume the maximum length of word is L, starting from a cell, initially we would have at most 4 directions to explore. Assume each direction is valid (i.e. worst case), during the following exploration, we have at most 3 neighbor cells (excluding the cell where we come from) to explore. As a result, we would traverse at most 4⋅3 L−1  cells during the backtracking exploration.
One might wonder what the worst case scenario looks like. Well, here is an example. Imagine, each of the cells in the board contains the letter a, and the word dictionary contains a single word ['aaaa']. Voila. This is one of the worst scenarios that the algorithm would encounter.
pic
Note that, the above time complexity is estimated under the assumption that the Trie data structure would not change once built. If we apply the optimization trick to gradually remove the nodes in Trie, we could greatly improve the time complexity, since the cost of backtracking would reduced to zero once we match all the words in the dictionary, i.e. the Trie becomes empty.


Space Complexity: O(N), where N is the total number of letters in the dictionary.
The main space consumed by the algorithm is the Trie data structure we build. In the worst case where there is no overlapping of prefixes among the words, the Trie would have as many nodes as the letters of all words. And optionally, one might keep a copy of words in the Trie as well. As a result, we might need 2N space for the Trie.
'''