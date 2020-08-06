#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int lli;
#define pb push_back
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
const int mod =1e9+7;



int main()
{
    speed;
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int dp[n+1];
    while(q--){
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        a1--;
        a2--;
        int ans=INT_MIN;
        for(int i=a1;i<=a2;i++)dp[i]=1;
        for(int i=a1+1;i<=a2;i++){
            if(a[i]==a[i-1]+a3){
                dp[i+1]=dp[i]+1;
                
            }
            else dp[i+1]=1;
            cout<<dp[i+1]<<endl;
            ans=max(ans,dp[i+1]);
        }
        
        cout<<ans<<endl;
    }
}


vector<pair<int,int>>ad[100000];
vector<pair<int,int>>T[10000];
bool visible[100000];
lli ener[1000000];

void init(lli n){
    F(i,0,n-1){
        visible[i]=false;
        ener[i]=1e9;
    }

}
void dijkastra(lli n){
    multiset<pair<int,int>>s;
    ener[n]=0;
    s.insert({0,n});
    while(!s.empty()){
        pair<int,int>p=*s.begin();
        s.erase(s.begin());
        int x=p.first;
        if(visible[x])continue;
        visible[x]=true;
        //cout<<x;
        F(i,0,ad[x].size()-1){
            int en1=ad[x][i].first;
            int t=ad[x][i].second;
            if(ener[t]>en1+ener[x]){
                ener[t]=en1+ener[x];
                s.insert({t,ener[t]});
            }
        }


    }
}


int main()
{
    speed;
    lli nc,nr,enr,from,to,dist,energy;
    cin>>nc>>nr>>enr;
    init(nc);
    F(i,1,nr){
        cin>>from>>to>>dist>>energy;
        ad[from-1].pb({energy,to-1});
        ad[to-1].pb({energy,from-1});
        T[from-1].pb({to-1,dist});
        T[to-1].pb({from-1,dist});
    }
    dijkastra(0);
    F(i,1,nr+3)cout<<ener[i]<<" ";
    
    return 0;
}