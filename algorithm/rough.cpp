#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
<<<<<<< HEAD
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
=======
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
>>>>>>> 4e1dc46759781f5165e6668e36a23c0b03142970
    }
    return 0;
}