#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;

void init(){

}

int dp1[1501][1501];
int dp2[1501][1501];

bool isPalin(string& s, int i, int j) {
    if (i >= j) return true;
    if (dp1[i][j] != -1) return dp1[i][j];
    if (s[i] == s[j]) return dp1[i][j] = isPalin(s, i + 1, j - 1);
    return dp1[i][j] = false;
}

int ff(string& s, int i, int j) {
    if (i >= j) return 0;
    if (isPalin(s, i, j)) return dp2[i][j] = 0;
    if (dp2[i][j] != -1) return dp2[i][j];
    
    int min_cuts = INT_MAX;
    
    for (int idx = i; idx <= j; idx++) {
        if (isPalin(s, i, idx)) {
            min_cuts = min(min_cuts, 1 + ff(s, idx + 1, j));
        }
    }
    
    return dp2[i][j] = min_cuts;
}

int minCut(string s) {
    memset(dp1, -1, sizeof dp1);
    memset(dp2, -1, sizeof dp2);
    return ff(s, 0, s.length() - 1);
}
 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       string s;
       cin>>s;
       int ans=minCut(s);
       cout<<ans<<endl;
   }
   return 0;
}