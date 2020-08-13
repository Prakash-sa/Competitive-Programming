//https://atcoder.jp/contests/dp/tasks/dp_j

#include<bits/stdc++.h>
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
using namespace std;
int n;
double dp[301][301][301];
    
double solve(int x, int y, int z){
    if(x<0 || y<0 || z<0)
        return 0.0;
    if(x==0&&y==0&&z==0)
        return 0.0;
    if(dp[x][y][z] > -0.9)
        return dp[x][y][z];
    double exp = n + x*solve(x-1,y,z) + y*solve(x+1,y-1,z) + z*solve(x,y+1,z-1);
    
    return dp[x][y][z] = exp/(x+y+z);
}
    
int main(){
    cin>>n;
    int x,y,z;
    x = y = z = 0;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t==1)
            x++;
        else if(t==2)
            y++;
        else
            z++;
    }
    //cout<<solve(x,y,z)<<endl;
    cout<<fixed<<setprecision(10)<<solve(x,y,z)<<endl;
    return 0;
}