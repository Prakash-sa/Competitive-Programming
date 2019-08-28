#include<bits/stdc++.h>
using namespace std;
/*
int GCD(int a,int b)
{
    if(b==0) return a;

    return GCD(b,a%b);

}


int main()
{
    cout<<"hi there";
    int k;
    k=GCD(270,192);
    cout<<k<<endl;

}
*/

long long x,y;
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

int main()
{
    int k,k1;
    cin>>k>>k1;
    int l=__gcd(k,k1);
    cout<<l;
    
}

