#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+9;
const int num=1e5+5;
lli dp[num+1];
lli ans[6][num+1]={0};

void init(){

}

int get_rand(int lo, int hi) {
    auto moment = chrono::steady_clock::now().time_since_epoch().count();
    int num = moment % (hi - lo + 1);
    return num + lo;
}

 
int main()
{
   boost;
   int t=1,h=1;
   cin>>t;
   while(t--){
      cout<<get_rand(1,8)<<endl;
   }
   return 0;
}
