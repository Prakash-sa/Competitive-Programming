# https://leetcode.com/problems/implement-trie-prefix-tree/description/

'''
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 
Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
'''

class TrieNode:
    def __init__(self):
        self.links=[None]*26
        self.is_end=False

    def contains_key(self,ch:str)->bool:
        return self.links[ord(ch)-ord('a')] is not None
    
    def get(self,ch: str)->'TrieNode':
        return self.links[ord(ch)-ord('a')]

    def put(self,ch: str, node:'TrieNode')->None:
        self.links[ord(ch)-ord('a')]=node

    def set_end(self)->None:
        self.is_end=True


class Trie:

    def __init__(self):
        self.root=TrieNode()

    def insert(self, word: str) -> None:
        node=self.root
        for ch in word:
            if not node.contains_key(ch):
                node.put(ch,TrieNode())
            node=node.get(ch)
        node.set_end()      


# Complexity Analysis

# Time Complexity: O(m), where m is the length of the key. Each operation involves examining or creating a node until the end of the key.
# Space Complexity: O(m). In the worst case, each newly inserted key might require adding m new nodes, resulting in O(m) space usage.  


    def search_prefix(self,word:str)->TrieNode:
        node=self.root
        for ch in word:
            if node.contains_key(ch):
                node=node.get(ch)
            else:
                return None
        return node

    def search(self, word: str) -> bool:
        node=self.search_prefix(word)
        return node is not None and node.is_end
    

# Complexity Analysis
# Time Complexity: O(m). Each step involves searching for the next character of the key, requiring m operations in the worst case.
# Space Complexity: O(1).


    def startsWith(self, prefix: str) -> bool:
        node=self.search_prefix(prefix)
        return node is not None
    
# Complexity Analysis
# Time Complexity: O(m).
# Space Complexity: O(1).



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)

