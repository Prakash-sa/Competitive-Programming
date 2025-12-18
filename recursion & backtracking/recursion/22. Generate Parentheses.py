# https://leetcode.com/problems/generate-parentheses/description/

'''
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
'''

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans=[]



        def backtrack(open,close,arr):
            if open==0 and close==0:
                ans.append("".join(arr[:]))
            
            if open>0:
                arr.append("(")
                backtrack(open-1,close,arr)
                arr.pop()
            
            if close>0:
                if open<close:
                    arr.append(")")
                    backtrack(open,close-1,arr)
                    arr.pop()

        backtrack(n,n,[])
        return ans

        
# Complexity Analysis
# Time complexity: O(4^n/ n^1/2)
# We only track the valid prefixes during the backtracking procedure. As explained in the approach 1 time complexity analysis, the total number of valid parentheses strings is O(4^n/nn).
# Please find the explanation behind this intuition in approach 3!
# You can also refer to Catalan number on Wikipedia for more information about Catalan numbers.
# When considering each valid string, it is important to note that we use a mutable instance (StringBuilder in Java, list in Python etc.). As a result, in order to add each instance of a valid string to answer, we must first convert it to a string. This process brings an additional n factor in the time complexity.

# Space complexity: O(n)
# The space complexity of a recursive call depends on the maximum depth of the recursive call stack, which is 2n. As each recursive call either adds a left parenthesis or a right parenthesis, and the total number of parentheses is 2n. Therefore, at most O(n) levels of recursion will be created, and each level consumes a constant amount of space.
