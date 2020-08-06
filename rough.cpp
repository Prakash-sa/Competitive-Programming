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
      string s;
      cin>>s;
      int a[n];
      a[0]=1;
      vector<int>ss[2];
      vector<int>sol(n);int k=0;
      for(int i=0;i<n;i++){
         int l=s[i]-'0';
         if(ss[l].empty()){
            sol[i]=k++;
         }
         else {
            sol[i]=ss[l].back();
            ss[l].pop_back();
         }
         ss[!l].push_back(sol[i]);
      }
      cout<<k<<endl;
      for(int i=0;i<n;i++)cout<<sol[i]+1<<" ";
      cout<<endl;
   }
   return 0;
}
