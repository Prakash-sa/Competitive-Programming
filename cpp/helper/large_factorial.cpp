#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<boost/multiprecision/cpp_int.hpp>
#include <algorithm>
using namespace std;
#define lli long long int
#define max1 10000
namespace mp=boost::multiprecision;


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
    int res[10000];
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
        int n;
        cin>>n;
        fac(n);
    }
    return 0;
}

//by boost cpp

int main() {
    lli n,t;
    cin>>t;
    while(t--){
        cin>>n;
        mp::cpp_int u=1;
        for(int i=1;i<=n;i++)u*=i;
            cout<<u<<endl;

    }
    return 0;
}