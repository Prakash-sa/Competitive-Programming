#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
int mod1= 1e9+7;


//https://codeforces.com/problemset/problem/474/D


lli dp[100007];
lli pre[100007];
int k;
int getans(int n){
  if(n==0)return 1;
  if(dp[n]!=-1)return dp[n];
  lli ans=0;
  if(n>=k)ans=(ans+getans(n-k))%mod1;
  ans=(ans+getans(n-1))%mod1;
  return dp[n]=ans;
}

int main(){
  boost;
  int q,n1,n2;
  cin>>q>>k;
  for(int i=0;i<100007;i++)dp[i]=-1;
  pre[0]=0;
  for(int i=1;i<100007;i++)pre[i]=(pre[i-1]+getans(i))%mod1;
  while (q--) {
      cin>>n1>>n2;
      int sum=(pre[n2]-pre[n1-1]+mod1)%mod1;
      cout << sum << '\n';
  }
}
