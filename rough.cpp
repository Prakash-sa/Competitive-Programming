#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1000*1000*1000+5)

lli getR(lli a){
  while(a%2==0)a=a/2;
  return a;
}

int main(){
  boost;
  int t;
  cin>>t;
  while(t--){
    lli n;
    cin>>n;
    lli ans=0;
    for(int i=0;i<60;i++){
      if(n&(1LL<<i))ans+=(1LL<<(i+1))-1;
    }
    cout<<ans<<endl;
    
  }

return 0;
}
