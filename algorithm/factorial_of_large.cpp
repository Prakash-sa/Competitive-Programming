#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pb push_back
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int multi(int x,int res[],int si){
    int ca=0;
    for(int i=0;i<si;i++){
        int le=res[i]*x+ca;
        ca=le/10;
        res[i]=le%10;
    }
    while(ca){
        res[si]=ca%10;
        ca=ca/10;
        si++;
    }
    return si;
}

void fac(int n){
    int res[500];
    res[0]=1;
    int si=1;
    for(int i=2;i<=n;i++)si=multi(i,res,si);
    for(int i=si-1;i>=0;i--)cout<<res[i];
    cout<<endl;
}

int main()
{
    speed;
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        fac(n);
    }
    return 0;
}