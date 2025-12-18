# https://leetcode.com/problems/alien-dictionary/description/

'''
There is a new alien language that uses the English alphabet. However, the order of the letters is unknown to you.
You are given a list of strings words from the alien language's dictionary. Now it is claimed that the strings in words are sorted lexicographically by the rules of this new language.
If this claim is incorrect, and the given arrangement of string in words cannot correspond to any order of letters, return "".
Otherwise, return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there are multiple solutions, return any of them.

Example 1:
Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
Example 2:
Input: words = ["z","x"]
Output: "zx"
Example 3:
Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of only lowercase English letters.
'''


class Solution:
    def alienOrder(self, words: List[str]) -> str:
        unique=set("".join(words))
        graph=defaultdict(set)
        indegree={c:0 for c in unique}

        for i in range(len(words)-1):
            w1,w2=words[i],words[i+1]
            min_len=min(len(w1),len(w2))
            
            if len(w1)>len(w2) and w1[:min_len]==w2[:min_len]:
                return ""

            for j in range(min_len):
                if w1[j]!=w2[j]:
                    if w2[j] not in graph[w1[j]]:
                        graph[w1[j]].add(w2[j])
                        indegree[w2[j]]+=1
                    break
        # Step 3: topological sort (Kahn's algorithm)
        queue = deque([c for c in indegree if indegree[c] == 0])
        order = []
        
        while queue:
            ch = queue.popleft()
            order.append(ch)
            
            for nei in graph[ch]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    queue.append(nei)
        
        # If we used all unique chars, we have a valid ordering.
        if len(order) == len(unique):
            return "".join(order)
        else:
            # Cycle or inconsistency in constraints
            return ""
        
# Step 1: Collect unique characters

# This scans all characters in all words.

# O(T) where T = total number of characters in input
# Final Total Time Complexity: O(T+E)



# Time Complexity:O(T+E)(effectively O(T))
# Space Complexity: O(U+E)(effectively O(1))