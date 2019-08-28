#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007

#define max 1000000
lli BIT[max],a[max],n,f[max],phi[max];

void seive(){
    F(i,1,max-1)phi[i]=i;
    F(i,2,max-1){
        if(phi[i]==i){
            for(lli j=i;j<max;j+=i){
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
    for(lli i=1;i<max;i++){
        for(lli j=i;j<max;j+=i){
            f[j]+=i*phi[j/i];
            if(f[j]>=mod)f[j]-=mod;
        }
    }



}


// lli func(lli x){
//     lli sum=0;
//     F(i,1,x)sum+=__gcd(i,x);
//     return sum;
// }

void update(lli i,lli val){
    //i--;
   // BIT[i]=val;
   //val=func(val)-func(BIT[i]);
    for(;i<=n;i+=i&(-i)) BIT[i]=(BIT[i]+val)%mod;
}

lli query(lli x){
    lli sum=0;
    lli i;
    for(; x > 0; x -= x&(-x)) sum=(sum+BIT[x])%mod;
    return sum;
}

int main()
{
    //speed;
    lli n1,t;
    seive();
    cin>>n;
    F(i,1,n)
    {
        cin>>a[i];
        update(i,f[a[i]]);
    }
    char c;
    lli t1,t2;
    cin>>t;
    //cout<<t;
    while(t--){
        cin>>c>>t1>>t2;
        if(c=='C'){
             //cout<<"noe";
             lli ans=(query(t2)-query(t1-1))%mod;
             while(ans<0)ans+=mod;
             cout<<(query(t2)-query(t1-1))%mod<<endl;
        }
        else if(c=='U'){
            //cout<<"u are";
            //lli k=func(t2)-func(a[t1]);
            update(t1,f[t2]-f[a[t1]]);
        }
    //    else cout<<" open ";
    }


    return 0;
}