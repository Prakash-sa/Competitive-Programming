//https://practice.geeksforgeeks.org/problems/word-wrap1646/1#








class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        
        int n=nums.size();
       vector<int>dp(n);
       int cost=0,currlen;
       dp[n-1]=0;
       for(int i=n-2;i>=0;i--){
           currlen=-1;
           dp[i]=INT_MAX;
           for(int j=i;j<n;j++){
               currlen+=(nums[j]+1);
               if(currlen>k)
                break;
               if(j==n-1)
                cost=0;
               else
                cost=(k-currlen)*(k-currlen)+dp[j+1];
                 
                dp[i]=min(dp[i],cost);
           }
       }
        return dp[0];  
    } 
};
