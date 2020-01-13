#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
const int mod =1e9+7;



int main()
{
    speed;
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int dp[n+1];
    while(q--){
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        a1--;
        a2--;
        int ans=INT_MIN;
        for(int i=a1;i<=a2;i++)dp[i]=1;
        for(int i=a1+1;i<=a2;i++){
            if(a[i]==a[i-1]+a3){
                dp[i+1]=dp[i]+1;
                
            }
            else dp[i+1]=1;
            cout<<dp[i+1]<<endl;
            ans=max(ans,dp[i+1]);
        }
        
        cout<<ans<<endl;
    }

    return 0;
}