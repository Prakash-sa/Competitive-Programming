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
    string s;
    cin>>s;
    int zero=0,one=0;
    for(int i=0;i<s.size();i++){
      if(s[i]=='0')zero++;
      else one++;
    }
    int ans=min(one,zero);
    int pre0=0,pre1=0;
    for(int i=0;i<s.size();i++){
      pre0+=(s[i]=='0'),zero-=(s[i]=='0');
      pre1+=(s[i]=='1'),one-=(s[i]=='1');
      ans=min(ans,pre1+zero);
      ans=min(ans,pre0+one);
    }
    cout<<ans<<endl;
  }
  return 0;
}
