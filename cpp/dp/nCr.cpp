//https://practice.geeksforgeeks.org/problems/ncr1019/1




#define lli long long int
#define m 1000000007

lli ncr(int n,int k){
    lli c[n+1][k+1]={0};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0||j==i)c[i][j]=1;
            else c[i][j]=(c[i-1][j]%m+c[i-1][j-1]%m)%m;
        }
    }
    return c[n][k];
}
 
int main()
 {
	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	cout<<ncr(n,k)<<endl;
	}
	return 0;
}
