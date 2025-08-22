//https://atcoder.jp/contests/dp/tasks/dp_i

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
      int n;
      cin>>n;
      cout<<fixed<<setprecision(10);
      double a[n];
      for(int i=0;i<n;i++)cin>>a[i];
      double dp[n+1][n+1];
      memset(dp,0.0,sizeof(dp));
      dp[0][0]=1;
      for(int i=1;i<=n;i++){
         for(int j=0;j<=i;j++){
            if(j==0)dp[i][j]=dp[i-1][j]*(1-a[i-1]);
            else dp[i][j]=dp[i-1][j]*(1-a[i-1])+dp[i-1][j-1]*a[i-1];   
         }
      }
      double ans=0.0;
      for(int i=n;i>n/2;i--)ans+=dp[n][i];
      cout<<ans<<endl;
   }
   return 0;
}
