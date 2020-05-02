#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
  boost;
  int t;
  cin>>t;
  while(t--){
    vector<int>v(n);
    int n;
    int sum=0;
    for(int i=0;i<n;i++)sum+=v[i];
    int dp[v.size()+1][sum+1];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<=stones.size();i++)dp[i][0]=false;
    for(int i=0;i<stones.size();i++){
      for(int j=0;j<=sum;j++){
        dp[i][j]=dp[i-1][j];
        if(stones[i-1]<=j){
          dp[i][j]=dp[i][j]||dp[i-1][j-stones[i-1]];
        }
      }
    }
    int diff=INT_MAX;
    for(int i=sum/2;j>=0;j--){
      if(dp[stones.size()][j]){
        diff=sum-j-j;
        break;
      }
    }
    cout<<diff<<endl;
  }
}
