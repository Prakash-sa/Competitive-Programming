//https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1#


class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<int>arr;
        vector<int>w;
        for(int i=0;i<N;i++){
            if(cost[i]!=-1){
                arr.push_back(cost[i]);
                w.push_back(i+1);
            }
        }
        
        vector<vector<int>>dp(arr.size()+1,vector<int>(W+1,0));
        for(int i=1;i<=W;i++)dp[0][i]=INT_MAX-1000;
        for(int i=1;i<=arr.size();i++){
            for(int j=1;j<=W;j++){
                if(w[i-1]>j)dp[i][j]=dp[i-1][j];
                else dp[i][j]=min(dp[i-1][j],dp[i][j-w[i-1]]+arr[i-1]);
            }
        }
        int n=arr.size();
        if(dp[n][W]==INT_MAX)return -1;
        return dp[n][W];
	} 
};
