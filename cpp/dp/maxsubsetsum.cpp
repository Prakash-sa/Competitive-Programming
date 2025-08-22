#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int MOD=11380,dp[11][11][11][31];

int maxSubsetSum(vector<int> a) {
    int inc=a[0],exc=0,new_exc;
    for(int i=1;i<a.size();i++){
        new_exc=max(inc,exc);
        inc=exc+a[i];
        exc=new_exc;
    }
    return max(inc,exc);    
}

int main()
{
    //speed;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<maxSubsetSum(a)<<endl;
    }
    return 0;
}
