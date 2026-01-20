# https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

'''
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters. 

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
'''

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits)==0:
            return []

        letters={
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz",
        }

        def backtrack(index,path):
            if len(path)==len(digits):
                combinations.append("".join(path))
                return
            
            possible_letters=letters[digits[index]]
            for letter in possible_letters:
                path.append(letter)
                backtrack(index+1,path)
                path.pop()
            
        combinations=[]
        backtrack(0,[])
        return combinations


# Complexity Analysis
# Time complexity: O((4^N)⋅N)
# Space complexity: O(N), where N is the length of digits.
