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
bool isPrime(lli n) {
    for (lli i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
long long extended_gcd(long long a,long long b)
{
    if(b==0)
    {
        //x=1;y=0;
        return a;
    }
    long long g=extended_gcd(b,a%b);
    // long long x1=x;
    // long long y1=y;
    // x=y1;
    // y=x1-((a/b)*y1);
    return g;

}

lli modulo(lli x,lli N){
    return (x % N + N) %N;
}

int main()
{
    speed;
    lli l1,l2;
    cin>>l1>>l2;
    lli k1=l1,k2;
    
    for(lli i=l1+1;i<=l2;i++){
        if(extended_gcd(l1,i)==1){
            lli c=l1+i;
            if((extended_gcd(c,l1)==1)&&(extended_gcd(c,i)==1)){
                k2=i;
                break;
            }
        }
    }
    cout<<k1<<" "<<k2;
    return 0;
}