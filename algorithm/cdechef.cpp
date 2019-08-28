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
    lli n,m;
    cin>>n;
    lli a[n];
    for(lli i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(lli i=1;i<n;i++){
        a[i]=a[i]-a[i-1];
       
    }
    if(a[n-1]==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}