# https://leetcode.com/problems/greatest-common-divisor-of-strings/description/

'''
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:
Input: str1 = "LEET", str2 = "CODE"
Output: ""

Constraints:
1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
'''

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1+str2!=str2+str1:
            return ""
        cnt=gcd(len(str1),len(str2))
        return str1[:cnt]
    
# Complexity Analysis
# Let m,n be the lengthes of the two input strings str1 and str2.
# Time complexity: O(m+n)
# We need to compare the two concatenations of length O(m+n), it takes O(m+n) time.
# We calculate the GCD using binary Euclidean algorithm, it takes log(m⋅n) time.
# To sum up, the overall time complexity is O(m+n).

# Space complexity: O(m+n)
# We need to compare the two concatenations of length O(m+n).


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        len1,len2=len(str1),len(str2)

        def valid(target):
            if len1%target or len2%target:
                return False
            n1,n2=len1//target,len2//target
            base=str1[:target]
            return str1==base*n1 and str2==base*n2
        
        for i in range(min(len1,len2),0,-1):
            if valid(i):
                return str1[:i]
        return ""

# Complexity Analysis
# Let m,n be the lengths of the two input strings str1 and str2.

# Time complexity: O(min(m,n)⋅(m+n))
# We checked every prefix string base of the shorter string among str1 and str2, and verify if both strings are made by multiples of base. There are up to min(m,n) prefix strings to verify and each check involves iterating over the two input strings to check if the current base is the GCD string, which costs O(m+n). Therefore, the overall time complexity is O(min(m,n)⋅(m+n)).

# Space complexity: O(min(m,n))
# We need to keep a copy of base in each iteration, which takes O(min(m,n)) space.
