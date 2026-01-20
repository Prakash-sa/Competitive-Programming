# https://leetcode.com/problems/verifying-an-alien-dictionary/description/

'''
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
'''

from collections import List, defaultdict

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        d=defaultdict(int)
        for i in range(len(order)):
            d[order[i]]=i
        
        def check(str1,str2):
            for i in range(min(len(str1),len(str2))):
                if d[str1[i]]>d[str2[i]]:
                    return False
                elif d[str1[i]]<d[str2[i]]:
                    return True
            
            if len(str1)>len(str2):
                return False

            return True
        
        for i in range(len(words)-1):
            if not check(words[i],words[i+1]):
                return False
        return True

# Complexity analysis
# Let N be the length of order, and M be the total number of characters in words.
# Time complexity : O(M).
# Storing the letter-order relation of each letter takes O(N) time. For the nested for-loops, we examine each pair of words in the outer-loop and for the inner loop, we check each letter in the current word. Therefore, we will iterate over all of letters in words.
# Taking both into consideration, the time complexity is O(M+N). However, we know that N is fixed as 26. Therefore, the time complexity is O(M).

# Space complexity : O(1).
# The only extra data structure we use is the hashmap/array that serves to store the letter-order relations for each word in order. Because the length of order is fixed as 26, this approach achieves constant space complexity.
    