#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

lli BIT[10000],a[1000],n;

void update(lli i,lli val){
    for(;i<=n;i+=i&(-i))BIT[i]+=val;
}

lli query(lli x){
    lli sum=0;
    for(;x>0;x-=x&-x)sum+=BIT[x];
    return sum;
}

int main()
{
    //speed;
    lli n1,t;
    cin>>n;
   // lli a[n];
    F(i,1,n)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    cout<<"enter something ";
    //cout<<"now"<<endl;
    cin>>t;
    cout<<query(t);



    return 0;
}