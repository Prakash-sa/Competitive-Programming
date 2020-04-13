#include<bits/stdc++.h>
using namespace stdc

int ch(int a[],int n){
  multiset<int>last;
  for(int i=0;i<n;i++){
    auto it=last.lower_bound(a[i]);
    if(it==last.begin())last.insert(a[i])
    else {
      it--;
      last.erase(it);
      last.insert(a[i]);
    }
  }
  return last.size();
}

int main(){
  int t;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<ch(a,n)<<endl;
  }
}
