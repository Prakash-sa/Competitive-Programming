#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
  boost;
  int t;
  cin>>t;
  while(t--){
    vector<int>v(n);
    int n;
    int sum=0;
    for(int i=0;i<n;i++)sum+=v[i];
    int dp[v.size()+1][sum+1];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<=stones.size();i++)dp[i][0]=false;
    for(int i=0;i<stones.size();i++){
      for(int j=0;j<=sum;j++){
        dp[i][j]=dp[i-1][j];
        if(stones[i-1]<=j){
          dp[i][j]=dp[i][j]||dp[i-1][j-stones[i-1]];
        }
      }
    }
    int diff=INT_MAX;
    for(int i=sum/2;j>=0;j--){
      if(dp[stones.size()][j]){
        diff=sum-j-j;
        break;
      }
    }
    cout<<diff<<endl;
  }
}


//Leetcode

/*
Try and understand the basic knapsack problem and how it's solved in two different ways.
We could either build the dp table top down or bottom up. 
The top down approach for knapsack with O(nW) runtime and O(nW) space is listed below:


https://leetcode.com/problems/ones-and-zeroes/


You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.
 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

*/


int knapsack(int val[], int wt[], int n, int W)
{
   int dp[n+1][W+1];
   memset(dp, 0, sizeof dp);
   for (int i = 1; i <= n; i++)
   {
       for (w = 1; w <= W; w++)
       {
           dp[i][w] = dp[i-1][w];  //don't include the item
           if (wt[i-1] <= w)
                 dp[i][w] = max(dp[i][w], 
                           val[i-1] + dp[i-1][w-wt[i-1]]);  
       }
   }
   return dp[n][W];
}

/*
The same knapsack problem could be solved with O(nW) runtime and O(W) space by building the table bottom up as shown below:
*/

int knapsack(int val[], int wt[], int n, int W)
{
    int dp[W+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i < n; i++) 
        for(int j=W; j>=wt[i]; j--)
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]);
    return dp[W];
}

/*
Coming to this problem, if you could understand how above approaches work, this problem is pretty similar with two knapsacks. 


Top down approach
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        int dp[len+1][m+1][n+1];
        memset(dp, 0, sizeof dp);
        
        for (int i=1;i<=len;i++){
            for (int j=0;j<=m;j++){
                for (int k=0;k<=n;k++){
                    int ones = count(strs[i-1].begin(), strs[i-1].end(), '1');
                    int zeros = strs[i-1].size()-ones;
                    int res = dp[i-1][j][k];
                    if (zeros<=j && ones<=k) 
                       res = max(res, dp[i-1][j-zeros][k-ones]+1);
                    dp[i][j][k] = res;
                }
            }
        }
        
        return dp[len][m][n];
        
    }
};


//Bottome Up Approach

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<strs.size();i++){
            int zeros=count(strs[i].begin(),strs[i].end(),'0');
            int ones=strs[i].size()-zeros;
            for(int j=n;j>=ones;j--){
                for(int k=m;k>=zeros;k--){
                    dp[j][k]=max(dp[j][k],dp[j-ones][k-zeros]+1);
                }
            }
        }
        return dp[n][m];
    }
};
