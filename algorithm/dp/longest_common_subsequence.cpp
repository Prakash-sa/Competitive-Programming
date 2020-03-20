int ch(char s1[],char s2[],int n1,int n2){
    int dp[n1+1][n2+1]={0};
    for(int i=0;i<=n1;i++)dp[i][0]=0;
    for(int i=0;i<=n2;i++)dp[0][i]=0;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n1,n2;
	    cin>>n1>>n2;
	    char s1[n1],s2[n2];
	    for(int i=0;i<n1;i++)cin>>s1[i];
	    for(int i=0;i<n2;i++)cin>>s2[i];
	    cout<<ch(s1,s2,n1,n2)<<endl;
	}
	return 0;
}