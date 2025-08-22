#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int MOD=11380,dp[11][11][11][31];

int solve(int l1,int l2,int l3,int d){
    if(d<0)return 0;
    if(l1+l2+l3==0)return 1;
    int &ret=dp[l1][l2][l3][d];
    if(ret==-1){
        ret=0;
        for(int i=0;i<l1;i++){
            for(int j=0;j<=l2;j++){
                for(int k=0;k<=l3;k++){
                    ret=(ret+solve(i,j,k,d-1)*solve(l1-i-1,l2-j,l3-k,d))%MOD;
                }
            }
        }
        for(int i=0;i<l2;i++){
            for(int j=0;j<=l3;j++){
                ret =(ret+solve(0,i,j,d-1)*solve(l1,l2-i-1,l3-j,d))%MOD;
            }
        }
        for(int i=0;i<l3;i++){
            ret=(ret+solve(0,0,i,d-1)*solve(l1,l2,l3-1-i,d))%MOD;
        }    
    }
    return ret;
}

int main()
{
    //speed;
    int l1,l2,l3,d;
    
    for(int i=0;i<3;i++){
        memset(dp,-1,sizeof(dp));
        cin>>l1>>l2>>l3>>d;
        int ans=solve(l1,l2,l3,d)-solve(l1,l2,l3,d-1);
        if(ans<0)ans+=MOD;
        cout<<ans<<endl;
    }
    return 0;
}
