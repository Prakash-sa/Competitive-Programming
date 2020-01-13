#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
double dp[1000][1000];

int main()
{
    speed;
    int t;
    cin>>t;
    while(t--){
        lli n,a,b;
        cin>>n;
        vector<pair<pair<lli,lli>,lli>>v;
        for(lli i=0;i<n;i++){
            cin>>a>>b;
            v.push_back({{a,b},i});
        }
        sort(v.begin(),v.end());
        int ans[n]={0};
        ans[0]=0;
        int cu=0;
        int ma=v[0].first.second;
        for(lli i=1;i<n;i++){
            int j=v[i].second;
            if(ma<=v[i].first.first){
                cu=0;
                ans[j]=cu;
                ma=v[i].first.second;
            }
            else if(ma<v[i].first.second){
                if(cu==0)cu=1;
                else cu=0;
                ans[j]=cu;
                ma=v[i].first.second;
            }
            else {
                if(cu==0)cu=1;
                else cu=0;
                ans[j]=cu;
            }
        }
        for(lli i=0;i<n;i++)cout<<ans[i];
        cout<<endl;
    }
    return 0;
}