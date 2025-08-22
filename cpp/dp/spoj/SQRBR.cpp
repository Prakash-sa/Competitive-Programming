#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
lli n,k,dp[50][50],op[50];

int recu(int pos,int open){
    if(open<0)return 0;
    if(pos==n)return (open==0);
    if(dp[pos][open]!=-1)return dp[pos][open];
    if(op[pos]){
        dp[pos][open]=recu(pos+1,open+1);
        return recu(pos+1,open+1);
    }
    dp[pos][open]=recu(pos+1,open+1)+recu(pos+1,open-1);
    return recu(pos+1,open+1)+recu(pos+1,open-1);
}

int main()
{
    speed;
    lli t,j;
    cin>>t;
    while(t--){
        cin>>n>>k;
        n=n<<1;
        memset(dp,-1,sizeof(dp));
        memset(op,0,sizeof(op));
        for(int i=0;i<k;i++){
            cin>>j;
            op[j-1]=1;
        }
        cout<<recu(0,0)<<endl;

    }

    return 0;
}
