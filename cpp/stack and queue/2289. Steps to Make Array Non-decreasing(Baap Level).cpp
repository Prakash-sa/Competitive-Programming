//https://leetcode.com/problems/steps-to-make-array-non-decreasing/



class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        int res=0;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>nums[st.top()]){
                dp[i]=max(++dp[i],dp[st.top()]);
                res=max(res,dp[i]);
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
