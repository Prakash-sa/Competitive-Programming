//https://leetcode.com/problems/generate-parentheses/




class Solution {
    vector<string>ans;
    
    void solve(string &s,int open,int close){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        
        if(open>0){
            s.push_back('(');
            solve(s,open-1,close);
            s.pop_back();
        }
        if(close>0){
            if(open<close){
                s.push_back(')');
                solve(s,open,close-1);
                s.pop_back();
            }
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string s="";
        solve(s,n,n);
        return ans;
    }
};

// https://leetcode.com/problems/generate-parentheses/
// python solution
// class Solution:
//     def generateParenthesis(self, n: int) -> List[str]:
//         stack = []
//         res = []
        
//         def backtrack(openN, closeN):
//             if openN == closeN == n:
//                 res.append("".join(stack))
//                 return 
//             if openN < n:
//                 stack.append("(")
//                 backtrack(openN+1, closeN)
//                 stack.pop()
                
//             if openN > closeN:
//                 stack.append(")")
//                 backtrack(openN, closeN+1)
//                 stack.pop()
        
//         backtrack(0,0)
//         return res

//  time complexity O(2^n)
//  space complexity O(2n) = O(n)