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
      int a[n];
      for(int i=0;i<n;i++)cin>>a[i];
      int pos=n-1;
     // cout<<n<<" ";
      while(pos>0 && a[pos-1]>=a[pos])pos--;
      while(pos>0 && a[pos-1]<=a[pos])pos--;
      cout<<pos<<endl;
      
   }
   return 0;
}
