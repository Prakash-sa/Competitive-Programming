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
       lli n;
       cin>>n;
       lli a[n],d[n];
       for(lli i=0;i<n;i++)cin>>d[i];
       for(lli i=0;i<n;i++)cin>>a[i];
       lli max1=0;
       
       for(lli i=0;i<n;i++){
           d[i]=2*d[i];
           max1=max(max1,d[i]);
       }
       lli dp[n+1][max1+1];
       for(lli i=0;i<=n;i++){
           for(lli j=0;j<=max1;j++)dp[i][j]=0;
       }


       lli m=max1;
       for(lli i=0;i<=m;i++)dp[0][i]=INT_MAX-1000;
    for(lli i=0;i<=n;i++)dp[i][0]=0;
    for(lli i=1;i<=n;i++){
        for(lli j=1;j<=m;j++){
             if(j<a[i-1])dp[i][j]=dp[i-1][j];
	         else dp[i][j]=min(dp[i-1][j],dp[i][j-a[i-1]]+1);
        }
    }
       lli sum=0;
       

       for(lli i=0;i<n;i++){
           sum+=dp[n][d[i]];
       }
        cout<<sum<<endl;


    }

	return 0;
}