#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;

int n;
vector<vector<int>>adj;
vector<bool>vis;
int k,res;
void init(){

}

int ch(int s,int d,int k){
    int dp[n][n][k+1];
    for(int e=0;e<=k;e++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j][e]=0;
                if(e==0&&i==j)dp[i][j][e]=1;
                if(e==1 && adj[i][j])dp[i][j][e]=1;
                if(e>1){
                    for(int a=0;a<n;a++){
                        if(adj[i][a])dp[i][j][e]+=dp[a][j][e-1];
                    }
                }
            }
        }
    }
    return dp[s][d][k];
}
 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       cin>>n;
       int s,d;
       vis.assign(n,false);
       adj.assign(n,{});
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               int a;
               cin>>a;
                adj[i].push_back(a);
           }
       }
       cin>>s>>d>>k;
       res=ch(s,d,k);
       cout<<res<<endl;
       
   }
   return 0;
}