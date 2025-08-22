//https://www.geeksforgeeks.org/coin-game-winner-every-player-three-choices/




class Solution{
    vector<int>dp;
    
    bool solve(int x,int y,int n){
        if(n==0)return dp[n]=0;
        if(n==1)return dp[n]=1;
        if(dp[n]!=-1)return dp[n];
        int op1=1,op2=1,op3=1;
        if(n>=x)op1=solve(x,y,n-x);
        if(n>=y)op2=solve(x,y,n-y);
        if(n>=1)op3=solve(x,y,n-1);
        if(!op1 || !op2 || !op3)dp[n]=1;
        else dp[n]=0;
        return dp[n];
    }
    
	public:
	int findWinner(int N, int X, int Y)
	{
		// Your code goes here
		dp.resize(N+1,-1);
		return solve(X,Y,N);
	}

};
