#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
  boost;
  int t;
  cin>>t;
  while(t--){
    int n,x,k;
    cin>>n>>x;
    set<int>s;
    for(int i=0;i<n;i++){
      cin>>k;
      s.insert(k);
    }
    std::vector<int> v,ans;
    int cnt=1;
    for(auto it=s.begin();it!=s.end();it++){
      ans.push_back(*it);
      v.push_back(*it-cnt++);
    }
    if(ans[0]!=1){
      x=x-ans[0];
    }
    int result;
    for(int i=1;i<ans.size();i++){
      if(ans[i-1]+1==ans[i])continue;
      else {
        if(x-ans[i]+ans[i-1]>=0){
          x=x-ans[i]+ans[i-1];
        }
        else {
          result=ans[i-1];
          break;
        }
      }
    }

  }
}
