#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

int getfactor(int x){
  int cnt=0;
  while (x%2==0) {
    cnt++;
    x=x/2;
  }
  for(int i=3;i<=sqrt(x);i+=2){
    while(x%i==0){
      cnt++;
      x=x/i;
    }
  }
  if(x>1)cnt++;
  return cnt;
}

int main(){
  boost;
  int t;
  cin>>t;
  while(t--){
    int n,x,k;
    cin>>n>>x;
    int k1=getfactor(n);
    cout<<k1;
    if(k1>=x)cout<<1;
    else cout<<0;
    cout<<"\n";

  }
}
