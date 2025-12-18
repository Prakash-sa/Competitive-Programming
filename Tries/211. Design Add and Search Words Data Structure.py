# https://leetcode.com/problems/design-add-and-search-words-data-structure/

'''
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.
'''


class TrieNode:
    def __init__(self):
        self.children=[None]*26
        self.is_end=False

    def contains_key(self, ch:str)->bool:
        return self.children[ord(ch)-ord('a')] is not None

    def get(self, ch:str)->'TrieNode':
        return self.children[ord(ch)-ord('a')]

    def put(self, ch:str, node:'TrieNode')->None:
        self.children[ord(ch)-ord('a')]=node
    
    def set_end(self)->None:
        self.is_end=True

class WordDictionary:

    def __init__(self):
        self.words=TrieNode()
    
    def addWord(self, word: str) -> None:
        node=self.words
        for ch in word:
            if not node.contains_key(ch):
                node.put(ch,TrieNode())
            node=node.get(ch)
        node.set_end()

    def search(self, word: str) -> bool:
        def dfs(node: Optional[TrieNode],i:int)->bool:
            if not node:
                return False
            
            if i==len(word):
                return node.is_end
            
            ch=word[i]
            if ch=='.':
                for nxt in node.children:
                    if nxt and dfs(nxt,i+1):
                        return True
                return False

            else:
                return dfs(node.get(ch),i+1)

        return dfs(self.words,0)
            

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
