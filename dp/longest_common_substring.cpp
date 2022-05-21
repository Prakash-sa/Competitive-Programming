int longestCommonSubstring(std::string s, std::string t) {
    int n=s.size(),m=t.size(),maxlen=0;
    int dp[n+1][m+1];
    int endindex;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)dp[i][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                maxlen=max(maxlen,dp[i][j]);
                if(maxlen<dp[i][j]){
                    maxlen=dp[i][j];
                    endindex=i;
                }
            }
        }
    }
    return maxlen;
    //string is 
    return s.substr(endindex-maxlen,mwaxlen);
}



//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1




int check(string s1,string s2,int n1,int n2)
{
    int lcs[n1+1][n2+1],max1=0;
    memset(lcs,0,sizeof(lcs));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
           if(s1[i-1]==s2[j-1]) lcs[i][j]=1+lcs[i-1][j-1];
            max1=max(lcs[i][j],max1);
        }
    }
    return max1;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n1,n2;
	    cin>>n1>>n2;
	    string s1,s2;
	    cin>>s1>>s2;
	    int k = check(s1,s2,n1,n2);
	    cout<<k<<endl;
	}
	return 0;
}
