//https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1#



class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        int ans=0;
        vector<int>dp(N+1,1);
        for(int i=0;i<N;i++){
            for(int j=0;j<i;j++){
                if(abs(A[i]-A[j])==1){
                    dp[i]=max(1+dp[j],dp[i]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};



