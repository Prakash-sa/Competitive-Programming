#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1000*1000*1000+5)

//https://www.codechef.com/LTIME83B/problems/SHUFFLE
lli mod=1e9+7;

int main(){
  boost;
  int t;
  cin>>t;
  while(t--){
    int n,k,val;
    cin>>n>>k;
    vector<int>v[100005];
    for(int i=0;i<n;i++){
      cin>>val;
      v[i%k].push_back(val);
    }
    int a[n];
    for(int i=0;i<k;i++){
      sort(v[i].begin(),v[i].end());
      for(int j=0;j<v[i].size();j++){
        a[j*k+i]=v[i][j];
      }
    }
    int flag=1;
    for(int i=0;i<n-1;i++){
      if(a[i]>a[i+1]){
        flag=0;
        break;
      }
    }
    if(flag)cout<<"yes";
    else cout<<"no";
    cout<<endl;

  }
return 0;
}
