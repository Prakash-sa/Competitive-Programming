#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
int dp[1000][1000];
int cal(int i,int j){
    if(i<=j)return dp[i][j];
    return 0;
}
int ch(int a[],int n){
    if(n==1)return a[0];
    if(n==2)return max(a[0],a[1]);

    for(int it=0;it<n;it++){
        for(int i=0,j=it;j<n;j++,i++){
            int st=a[i]+min(cal(i+2,j),cal(i+1,j-1));
            int en=a[j]+min(cal(i+1,j-1),cal(i,j-2));
            dp[i][j]=max(st,en);
        }
    }
    return dp[0][n-1];

}

int main()
{
    speed;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<ch(a,n)<<endl;
    }
    return 0;
}