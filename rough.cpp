#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef pair<lli,lli> PII;

int main()
{
    //speed;
    int ii=1;
    while(1){
        int n,m;
        cin>>n;
        if(n==0)break;
        string s,s1,s2;
        map<string,lli>mp;
        double adj[n+1][n+1];
        for(int i=1;i<=n;i++){
            cin>>s;
            mp[s]=i;
        }
        cin>>m;
        double l;
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)adj[i][j]=0;
        for(int i=1;i<=m;i++){
            cin>>s1>>l>>s2;
            adj[mp[s1]][mp[s2]]=l;
        }
        int flag=0;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    adj[i][j]=max(adj[i][j],adj[i][k]*adj[k][j]);
                }
             }
        }
        string ans;
        for(int i=1;i<=n;i++ ){
            if(adj[i][i]>1.0){
                flag=1;
                break;
            }
        }
        if(flag==1)ans="Yes";
        else ans="No";
        cout<<"Case "<<ii<<": "<<ans<<endl;
        ii++;
    }
    return 0;
}
