int ch(int a[],int n){
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=INT_MIN;
            if(i-a[0]>=0)dp[i]=max(dp[i],dp[i-a[0]]+1);
            if(i-a[1]>=0)dp[i]=max(dp[i],dp[i-a[1]]+1);
            if(i-a[2]>=0)dp[i]=max(dp[i],dp[i-a[2]]+1);
        
    }
    return dp[n];
}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[3];
	    for(int i=0;i<3;i++)cin>>a[i];
	    cout<<ch(a,n)<<endl;
	
	}
	return 0;
}