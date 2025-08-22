/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]


Example 2:
Input: prices = [1]
Output: 0
*/

class Solution {
    vector<vector<int>>dp;

    int dfs(int x,int flag,vector<int>&prices){
        if(x>=dp.size())return 0;
        if(dp[x][flag]!=-1)return dp[x][flag];

        int cooldown=dfs(x+1,flag,prices);
        if(flag){
            int buy=dfs(x+1,!flag,prices)-prices[x];
            dp[x][flag]=max(buy,cooldown);
        }
        else {
            int sell=dfs(x+2,!flag,prices)+prices[x];
            dp[x][flag]=max(sell,cooldown);
        }
        return dp[x][flag];
    }

public:
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return dfs(0,1,prices);
    }
};

