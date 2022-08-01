//https://leetcode.com/problems/longest-valid-parentheses/


/*
1, We count all the ‘(‘.
2, If we find a ‘)’ and ‘(‘ counter is not 0, we have at least a valid result size of 2. “()"
3, Check the the one before (i - 1). If DP[i - 1] is not 0 means we have something like this “(())” . 
This will have DP “0024"
4, We might have something before "(())”. Take "()(())” example, 
Check the i = 1 because this might be a consecutive valid string.
*/




class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),cnt=0;
        vector<int>dp(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')' && cnt>0){
                dp[i]=2+dp[i-1];
                if(i-dp[i]>0)dp[i]+=dp[i-dp[i]];
                cnt--;
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
