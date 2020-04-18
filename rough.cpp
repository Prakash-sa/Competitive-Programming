#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);


int main(){
  boost;
  int t,n,q;
  cin>>t;
  while (t--) {
    cin>>n>>q;
    int a[n+1],a1,b1;
    for(int i=1;i<=n;i++)cin>>a[i];
    int pre[n+1];
    int suf[n+1];
    pre[0]=0,suf[n+1]=0;
    for(int i=1;i<=n;i++)pre[i]=__gcd(pre[i-1],a[i]);
    for(int i=n;i>0;i--)suf[i]=__gcd(suf[i+1],a[i]);
    while(q--){
      cin>>a1>>b1;
      cout<<__gcd(pre[a1-1],suf[b1+1])<<endl;
    }
  }
}
