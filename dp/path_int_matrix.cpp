
long long int max(long long int a,long long int b){
    if(a>b)return a;
    else return b;
}

int me(vector<int> a[],int n){
    long long int dp[n+1][n+1]={0},l;
    for(int i=0;i<n;i++)dp[0][i]=a[0][i];
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j+1]);
            }
            else if(j==n-1){
                dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
            }
            else {
                dp[i][j]=a[i][j]+max(dp[i-1][j],max(dp[i-1][j+1],dp[i-1][j-1]));
            }
        }
    }
    long long int max1=0;
    for(int i=0;i<n;i++)max1=max(max1,dp[n-1][i]);
    return max1;

}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<int> a[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                cin>>k;
                a[i].push_back(k);
            }
         }

         cout<<me(a,n)<<endl;
    }

	
	return 0;
}

