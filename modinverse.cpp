#include<iostream>
using namespace std;

int modinverse(int a,int b)
{
    int k=0;
    for(int l=b;l>=0;l--)
    {
        if(((l*(a))%b)==1)
        {
            k=l;
        }
    }
    return k;
}
long long x,y;
long long extended_gcd(long long a,long long b)
{
    if(b==0)
    {
        x=1;y=0;return a;
    }
    long long g=extended_gcd(b,a%b);
    long long x1=x;
    long long y1=y;
    x=y1;
    y=x1-((a/b)*y1);
    return g;

}

int main()
{
    int k,j;
    cin>>k;
    int a[k],b[k];
    for(int l=0;l<k;l++)
    {
        cin>>a[l];
        cin>>b[l];

    }
    for(int l=0;l<k;l++)
    {
        int j=extended_gcd(a[l],b[l]);
        if(j==1){
            j=modinverse(a[l],b[l]);
            cout<<j<<endl;
        }
        else
        {
            cout<<-1;
        }
    }
    
    
}
