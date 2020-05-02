#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1000*1000*1000+5)


int main(){
  boost;
  int t,cnt=1;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    int m[n];
    for(int i=0;i<n;i++)cin>>m[i];
    int l=1,r=m[n-1]-m[0];
    while(l<r){
      int md=(l+r)/2;
      int k2=0;
      for(int i=1;i<n;i++){
        int d=m[i]-m[i-1];
        k2+=(d+md-1)/md-1;
      }
      if(k2<=k)r=md;
      else l=md+1;
    }

    cout<<"Case "<<"#"<<cnt<<": "<<l<<endl;
    cnt++;
  }
return 0;
}
