#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+7;
const lli num=1e5+5;

void init(){

}

int main()
{
   boost;
   int t;
   int cnt=1;
    cin>>t;
    cout<<__gcd(2,2)<<endl;
    
    while(t--){
      string s;
      int n;
      cin>>n>>s; 
       int ans=0;
       int cnt=0;
       for(int i=0;i<n;i++){
          if(s[i]=='0'){
             if(i!=0 && cnt>0)ans+=cnt;
             cnt=2;
          }
          else {
             cnt--;
          }
       }
       cout<<ans<<endl;
    }
   
   return 0;
}
