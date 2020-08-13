//https://atcoder.jp/contests/dp/tasks/dp_c

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
      int n;
      cin>>n;
      int a[n][3];
      for(int i=0;i<n;i++){
         for(int j=0;j<3;j++){
            cin>>a[i][j];
         }
      }
      lli dp[n+1][3];
      memset(dp,0,sizeof(dp));
      for(int i=1;i<=n;i++){
         for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
               if(j==k)continue;
               dp[i][k]=max(dp[i][k],dp[i-1][j]+a[i-1][k]);
            }
         }
      }
      lli ans=0;
      for(int i=0;i<3;i++)ans=max(ans,dp[n][i]);
      cout<<ans<<endl;
   }
   return 0;
}
