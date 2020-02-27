#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
<<<<<<< HEAD
#define gc getchar_unlocked
=======
#define mo 1000000007
/*#ifndef ONLINE_JUDGE
cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
*/


>>>>>>> 4e1dc46759781f5165e6668e36a23c0b03142970

int main()
{
    speed;
<<<<<<< HEAD
    int n1,n2;
    cin>>n1>>n2;
    lli n;
    cin>>n;
    if(n2==0)cout<<n<<endl;
    else if(n1==1)cout<<0<<endl;
    else {
    lli k=pow(10,n1-1);
    lli l=0,i=0;
    n2=n1-n2;
    while(n2&&n){
      l+=(n%10)*pow(10,i);
      i++;
      n2--;
      n=n/10;
    }
    cout<<k+l<<endl;
    }
=======
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
>>>>>>> 4e1dc46759781f5165e6668e36a23c0b03142970
}