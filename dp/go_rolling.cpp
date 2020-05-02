#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

//https://codeforces.com/problemset/problem/38/E

pair<int,int>ar[3001];
int n;
lli dp[3001][3001];
const long long int INF=1e15;

int getAns(int pos,int pre){
  if(pos>n)return 0;
  if(dp[pos][pre]!=-INF)return dp[pos][pre];
  //pin it
  int x=ar[pos].second+getAns(pos+1,pos);

  //leave it
  int y=abs(ar[pos].first-ar[pre].first)+getAns(pos+1,pre);

  return dp[pos][pre]=min(x,y);
}

int main(){
  boost;
  cin>>n;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++)dp[i][j]=-INF;
  }
  for(int i=1;i<=n;i++){
    cin>>ar[i].first>>ar[i].second;
  }
  sort(ar+1,ar+n+1);
  cout<<getAns(2,1)+ar[1].second<<endl;
}
