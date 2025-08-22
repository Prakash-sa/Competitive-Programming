//https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1#




class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here   
        sort(arr,arr+n);
        vector<int>dp(n+1,0);
        if(arr[1]-arr[0]<k)dp[1]=arr[1]+arr[0];
        else dp[1]=dp[0];
        for(int i=2;i<n;i++){
            if((arr[i]-arr[i-1])<k){
                dp[i]=max(dp[i-1],dp[i-2]+arr[i]+arr[i-1]);
            }
            else {
                dp[i]=dp[i-1];
            }
        }
        return dp[n-1];
    }
};
