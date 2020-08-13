//https://atcoder.jp/contests/dp/tasks/dp_h

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+7;
const lli num=1e5+5;

void init(){

}


int main()
{
   boost;
   int t=1;
   //cin>>t;
   init();
   while(t--){
      int n,m;
      cin>>n>>m;
      char a[n][m];
      for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
      int dp[n][m];
      memset(dp,0,sizeof(dp));
      dp[0][0]=1;
      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            if(a[i][j]=='#'){
               dp[i][j]=0;
               continue;
            }
            if(i==0&&j==0)continue;
            if(i==0)dp[i][j]=dp[i][j-1];
            else if(j==0)dp[i][j]=dp[i-1][j];
            else dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j-1])%mod;
         }
      }
      cout<<dp[n-1][m-1]<<endl;
   }
   return 0;
}
