#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    speed;
    lli t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        lli a[n];
        for(lli i=0;i<n;i++)cin>>a[i];
        lli sum=0;
        for(lli i=0;i<n;i++)sum+=m^a[i];
        cout<<sum<<endl;
    }
    
    
}