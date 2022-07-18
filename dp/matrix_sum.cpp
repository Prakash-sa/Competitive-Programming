#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< lli,lli> pll;
typedef map< lli,lli> mll;
typedef map< int,int> mii;
lli sum[1001][1001];
lli a[1001][1001];

lli tot(lli a[1001][1001],lli n1,lli n2){
    if(sum[n1][n2]!=-1) return sum[n1][n2];
    return sum[n1][n2]=tot(a,n1-1,n2)+tot(a,n1,n2-1)-tot(a,n1-1,n2-1)+a[n1][n2];
}

int main()
{
    lli n1,n2;
    cin>>n1>>n2;
   // lli a[n1][n2];
    memset(sum,-1,sizeof(sum));
    F(i,0,n1-1){2103
        F(j,0,n2-1)cin>>a[i][j];
       
    }
    sum[0][0]=a[0][0];
    
    F(i,1,n2-1)sum[0][i]=a[0][i]+sum[0][i-1];
    F(i,1,n1-1)sum[i][0]=a[i][0]+sum[i-1][0];
    
    lli q,t1,t2;
    cin>>q;
    
    while(q--){
        cin>>t1>>t2;
       
        lli res=tot(a,t1-1,t2-1);
        cout<<sum[t1-1][t2-1]<<endl;

    }


    return 0;
}