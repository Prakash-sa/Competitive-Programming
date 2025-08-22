//https://atcoder.jp/contests/dp/tasks/dp_k

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
      int n,k;
      cin>>n>>k;
      int a[n];
      for(int i=0;i<n;i++)cin>>a[i];
      int dp[k+1];
      memset(dp,false,sizeof(dp));
      for(int i=0;i<=k;i++){
         for(auto x:a){
            if(i>=x && !dp[i-x])dp[i]=true;
         }
      }
      if(dp[k])cout<<"First\n";
      else cout<<"Second\n";
      
   }
   return 0;
}
