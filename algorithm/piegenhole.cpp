#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1000*1000*1000+5)

//https://codeforces.com/contest/1342/problem/D

int main(){
  boost;
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  vector<int>c(k+1);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=1;i<=k;i++)cin>>c[i];
  sort(a.begin(),a.end(),greater<int>());
  int ans=0;
  for(int i=k,g=0;i>=1;i--){
    while(g<n && a[g]==i)g++;
    ans=max(ans,(g+c[i]-1)/c[i]);
  }
  vector<vector<int>>res(ans);
  for(int i=0;i<n;i++)res[i%ans].push_back(a[i]);
  cout<<ans<<endl;
  for(int i=0;i<ans;i++){
    cout<<res[i].size()<<" ";
    for(int j=0;j<res[i].size();j++)cout<<res[i][j]<<" ";
    cout<<endl;
  }

return 0;
}
