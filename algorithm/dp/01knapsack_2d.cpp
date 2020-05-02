#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1000*1000*1000+5)

//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb

int main(){
  boost;
  int t,cnt=1;
  cin>>t;
  while(t--){
    int n,k,p;
    cin>>n>>k>>p;
    int v,sum[n+1][k+1];
    memset(sum,0,sizeof(sum));
    for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)sum[i][j]=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=k;j++){
        cin>>v;
        sum[i][j]=v+sum[i][j-1];
      }
    }
    int dp[n+1][n*k+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
      for(int j=0;j<=p;j++){
        dp[i][j]=0;
        for(int x=0;x<=min(j,k);x++)dp[i][j]=max(dp[i][j],sum[i][x]+dp[i-1][j-x]);
      }
    }
    cout<<dp[n][p]<<endl;
  }
return 0;
}
