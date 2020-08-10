#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+7;
const lli num=2000000;

vector<lli>a(num);
vector<lli>g(num);
void init(){
   g[1]=1;
   for(lli i=2;i<num;i++)g[i]=1+g[i+1-g[g[i-1]]];
   for(lli i=2;i<num;i++)g[i]=(g[i]%mod*g[i]%mod)%mod;
   for(int i=2;i<num;i++)g[i]=(g[i]%mod+g[i-1]%mod)%mod;
}

bool ch(double x){
   if((int)x==x)return true;
   return false;
}

int main()
{
   boost;
   int t=1;
   //cin>>t;
   init();
   while(t--){
      int n;
      cin>>n;
      double a[n];
      set<double>s;
      for(int i=0;i<n;i++){
         cin>>a[i];
         s.insert(a[i]);
      }
      int cnt=0;
      for(int i=0;i<n;i++){
         double 
      }
      cout<<cnt<<endl;
   }
   return 0;
}
