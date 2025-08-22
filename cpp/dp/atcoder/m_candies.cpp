//https://atcoder.jp/contests/dp/tasks/dp_m

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+7;
const lli num=2000000;

void init(){

}


int main()
{
   boost;
   int t=1;
   //cin>>t;
   init();
   while(t--){
      int n,k;
      cin>>n>>k;
      int a[n];
      for(int i=0;i<n;i++)cin>>a[i];
      int dp[n+1][k+2];
      memset(dp,0,sizeof(dp));
      dp[0][0]=1;
      for(int i=1;i<=n;i++){
         vector<int>sum(k+1);
         sum[0]=dp[i-1][0];
         for(int j=1;j<=k;j++)sum[j]=(sum[j-1]+dp[i-1][j])%mod;
         for(int j=0;j<=k;j++){
            int not_ex=j-a[i-1]-1;
            if(j<=a[i-1])dp[i][j]=sum[j];
            else dp[i][j]=(sum[j]-sum[not_ex]+mod)%mod;
         }
         sum.clear();
      }
      cout<<dp[n][k]<<endl;
   }
   return 0;
}
