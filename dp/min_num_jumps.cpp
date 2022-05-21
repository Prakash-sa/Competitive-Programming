//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#





class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here


//DP solution 

        
        // vector<int>dp(n,INT_MAX);
        // if(n==1 && arr[0]==0)return 0;
        // if(arr[0]==0 )return -1;
        // dp[0]=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<=i+arr[i] && j<n;j++){
        //         if(dp[i]!=INT_MAX)
        //         dp[j]=min(dp[j],dp[i]+1);
        //     }
        // }
        // if(dp[n-1]==INT_MAX)return -1;
        // return dp[n-1];


//O(N) solution        
        if(n==1)return 0;
        if(arr[0]==0)return -1;
        int halt=0,maxR=INT_MIN,jump=0;
        for(int i=0;i<n-1;i++){
            maxR=max(maxR,i+arr[i]);
            if(i==halt){
                halt=maxR;
                jump++;
                if(halt>=n-1)return jump;
            }
        }
        return -1;
    }
};
