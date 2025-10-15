# https://leetcode.com/problems/number-of-matching-subsequences/description/

'''
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".

Example 1:
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 

Constraints:
1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
'''

class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        freq=defaultdict(list)

        for i,ch in enumerate(s):
            freq[ch].append(i)
        

        def check(st):

            prev=-1
            for ch in st:
                if ch not in freq:
                    return False
                idx_in_list=bisect_right(freq[ch],prev)
                if idx_in_list==len(freq[ch]):
                    return False
                prev=freq[ch][idx_in_list]
            return True


        ans=0

        for word in words:
            if check(word):
                ans+=1
        return ans
       

# Total Time Complexity: O(|s| + W * L * log |s|)
# Total Space Complexity: O(|s|)