#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;

int dp[21][21];
int n,m;
void init(){

}


//https://www.geeksforgeeks.org/gold-mine-problem/


int getMaxGold() 
{ 
    int goldTable[m][n]; 
    memset(goldTable, 0, sizeof(goldTable)); 
    for (int col=n-1; col>=0; col--) 
    { 
        for (int row=0; row<m; row++) 
        { 
            int right = (col==n-1)? 0: goldTable[row][col+1]; 
            int right_up = (row==0 || col==n-1)? 0:goldTable[row-1][col+1]; 
            int right_down = (row==m-1 || col==n-1)? 0:goldTable[row+1][col+1]; 
            goldTable[row][col] = dp[row][col] + max(right, max(right_up, right_down)); 
        } 
    }
    int res = goldTable[0][0]; 
    for (int i=1; i<m; i++) 
        res = max(res, goldTable[i][0]); 
    return res; 
} 
 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       cin>>m>>n;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++)cin>>dp[i][j];
       }
       cout<<getMaxGold()<<endl;
   }
   return 0;
}