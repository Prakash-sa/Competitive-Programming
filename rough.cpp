#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1000*1000*1000+5)


int main(){
  boost;
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    if(n<4){
      cout<<-1<<endl;
      continue;
    }
    for(int i=n;i>0;i--){
      if(i&1)cout<<i<<" ";
    }
    cout<<4<<" "<<2<<" ";
    for(int i=6;i<=n;i+=2)cout<<i<<" ";
    cout<<endl;
  }
return 0;
}
