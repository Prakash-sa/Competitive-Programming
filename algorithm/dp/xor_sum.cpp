#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mo 1000000007
lli n;
int main()
{
    speed;
    lli t;
    cin>>t;
    while(t--){
       lli n,k;
       cin>>n>>k;
       lli a[n+1];
       for(lli i=1;i<=n;i++)cin>>a[i];
        bool dp[n+1][1024];
        memset(dp,false,sizeof(dp));
        for(lli i=0;i<=n;i++)dp[i][0]=true;
        for(lli i=1;i<=n;i++){
            for(lli j=0;j<1024;j++){
                dp[i][j]=dp[i-1][j]||dp[i-1][j^a[i]];
            }
        }
        lli ans=0;
        for(lli i=0;i<1024;i++){
            if(dp[n][i]){
                lli te=i^k;
                ans=max(te,ans);
            }
        }
        cout<<ans<<endl;
      
    }

	return 0;
}