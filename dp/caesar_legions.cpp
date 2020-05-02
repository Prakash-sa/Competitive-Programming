#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod1 100000000

int limit_n1,limit_n2;
int dp [101][101][11][11];
int ch(int n1,int n2,int k1,int k2){
  if(n1+n2==0)return 1;
  if(dp[n1][n2][k1][k2]!=-1)return dp[n1][n2][k1][k2];
  int x=0;
  if(n1>0 && k1>0)x=ch(n1-1,n2,k1-1,limit_n2);
  int y=0;
  if(n2>0&&k2>0)y=ch(n1,n2-1,limit_n1,k2-1);
  return dp[n1][n2][k1][k2]=(x+y)%mod1;
}


int main(){
  boost;
  int n1,n2,k1,k2;
  cin>>n1>>n2>>k1>>k2;
  limit_n1=k1;
  limit_n2=k2;
  memset(dp,-1,sizeof(dp));
  cout<<ch(n1,n2,k1,k2)<<"\n";

}
