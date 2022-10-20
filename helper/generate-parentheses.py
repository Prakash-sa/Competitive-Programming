# https://leetcode.com/problems/generate-parentheses/
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        res = []
        
        def backtrack(openN, closeN):
            if openN == closeN == n:
                res.append("".join(stack))
                return 
            if openN < n:
                stack.append("(")
                backtrack(openN+1, closeN)
                stack.pop()
                
            if openN > closeN:
                stack.append(")")
                backtrack(openN, closeN+1)
                stack.pop()
        
        backtrack(0,0)
        return res

# time complexity O(2^n)
# space complexity O(2n) = O(n)