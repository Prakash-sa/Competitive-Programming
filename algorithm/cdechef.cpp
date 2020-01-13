
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define pii pair<ll,ll>
#define fi first
#define sc second
#define mod 1000000007
ll f[1000005];

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int li=n;
        n=sqrt(n);
        int pri[n+1];
        for(int i=0;i<=n;i++)pri[i]=i;
        for(int i=2;i*i<=n;i++){
            if(pri[i]==i){
                for(int j=2;i*j<=n;j++)if(pri[i*j]==i*j)pri[j*i]=i;
            }
        }
        int cnt=0;
        for(int i=2;i<=n;i++){
            int p=pri[i];
            int q=pri[i/p];
            if(p*q==i&&q!=1&&p!=q)cnt++;
            else if(pri[i]==i){
                if(pow(i,8)<=li)cnt++;
            }
        }
        cout<<cnt<<endl;

    }


}