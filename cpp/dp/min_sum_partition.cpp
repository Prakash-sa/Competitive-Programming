int sum;
long long int dp[1025][1025];
int ch(int s[],int n,int s1){
    if(n<0)return abs(sum-2*s1);
    if(dp[n][s1]==-1)dp[n][s1]=ch(s,n-1,s1);
    if(dp[n][s1+s[n]]==-1)dp[n][s1+s[n]]=ch(s,n-1,s1+s[n]);
    return min(dp[n][s1],dp[n][s1+s[n]]);
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    sum=0;
	    for(int i=0;i<n;i++)cin>>a[i];
	    for(int i=0;i<n;i++)sum+=a[i];
	    memset(dp,-1,sizeof(dp));
	    cout<<ch(a,n-1,0)<<endl;
	
	}
	return 0;
}