#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+9;
const int num=1e5+5;
vector<vector<int>>adj(20);
vector<bool>vis(20);
void init(){

}


int main()
{
   boost;
   int t=1,h=1;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      string a,b;
      cin>>a>>b;
      vector<int>ans;
      for(int i=0;i<n;i++){
         if(a[i]!=b[i]){
            if(i>0)ans.push_back(i+1);
            ans.push_back(1);
            if(i>0)ans.push_back(i+1);
         }
      }cout<<ans.size()<<" ";
      for(auto v:ans)cout<<v<<" ";
      cout<<endl;
   }
   return 0;
}
