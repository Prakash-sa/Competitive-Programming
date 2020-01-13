#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< lli,lli> pll;
typedef map< lli,lli> mll;
typedef map< int,int> mii;

int main()
{
    boost;
    lli t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>k>>n;
        lli a[n];
        lli ans=0;
        for(lli i=0;i<n;i++)cin>>a[i];
        for(lli i=1;i<(1<<n);i++){
            lli x=1;
            for(lli j=0;j<n;j++){
                if(i&(1<<j))
                x=x*a[j]/(__gcd(x,a[j]));
            }
            if(__builtin_popcount(i)&1)ans+=k/x;
            else ans-=k/x;
        }
        cout<<ans<<endl;
    }
    return 0;
}