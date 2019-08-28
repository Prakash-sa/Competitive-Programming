#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mo 1000000007
/*#ifndef ONLINE_JUDGE
cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
*/



int main()
{
    speed;
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        double k=(double)1/(2*n);
        lli ans=((1%mo)*((lli)k%mo))%mo;
        cout<<ans<<endl;

    }
    return 0;
}