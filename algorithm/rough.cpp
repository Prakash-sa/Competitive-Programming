#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< lli,lli> pll;
typedef map< lli,lli> mll;
typedef map< int,int> mii;

int main()
{
    boost;
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli a[10]={6,2,5,5,4,5,6,3,7,6};
        lli cnt=0;
        if(n==0)cnt=a[0];
        while(n){
            int k=n%10;
            cnt+=a[k];
            n=n/10;
        }
        if(cnt%2==0){
            for(lli i=0;i<cnt/2;i++)cout<<"1";
            cout<<endl;
        }
        else {
            for(lli i=0;i<cnt/2-1;i++)cout<<"1";
            cout<<"7"<<endl;
        }
    }
    return 0;
}