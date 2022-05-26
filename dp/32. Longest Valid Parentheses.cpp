//https://leetcode.com/problems/longest-valid-parentheses/





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
