int maxProfit(const vector<int> &A) {
    int j=0,n=A.size();
    int profit=0;
    for(int i=1;i<A.size();i++){
        if(A[i-1]>A[i])j=i;
        if(A[i-1]<=A[i] &&( i+1==n || A[i]>A[i+1])){
            profit+=A[i]-A[j];
        }
    }
    return profit;
}



//Buy and Sell Stock:1
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

*/
int maxProfit(vector<int>& prices) {
   int buy = INT_MAX;
   int sell = 0;
  for (int price : prices) {
        // the maximum profit if only one transaction is allowed
        buy = min(buy, price);
        sell = max(sell, price - buy);
    }
        return sell;
  }
//Buy and Sell Stock:2

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
However, you can buy it then immediately sell it on the same day. Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/
//Method 1:
int maxProfit2(vector<int>& prices) {
      int maxprofit = 0;
      for (int i = 1; i < prices.size(); i++) {
          if (prices[i] > prices[i - 1])
              maxprofit += prices[i] - prices[i - 1];
      }
      return maxprofit;
  }
//Method 2:
int maxProfit2(vector<int>& prices) {
      int buy = INT_MAX;
      int sell = 0;
       for (int price : prices) {
           buy = min(buy, price-sell); //Use the previous profit for reinvetsment and minimize expenditure
           sell = max(sell, price - buy);
       }
       return sell;
   }

//Buy and Sell Stock:3
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/
//Method 1:
int maxProfit3(int* prices, int pricesSize){
    int len = pricesSize;
    if(len == 0)
        return 0;
    int min_so_far = prices[0];
    int max_so_far = prices[len-1];
    int max_profit = 0;
    int maxProf[len];
    memset(maxProf,0,len*sizeof(int));

    for(int i=1;i<len; i++){
        int profit = (prices[i] - min_so_far) ;
        max_profit = max_profit > profit ? max_profit : profit;
        maxProf[i] = max_profit;
        min_so_far = min_so_far < prices[i] ? min_so_far : prices[i];
    }

    for(int i = len-2;i>0;i--){
        int profit = (max_so_far - prices[i])+maxProf[i];
         max_profit = max_profit > profit ? max_profit : profit;
        max_so_far = max_so_far > prices[i] ? max_so_far : prices[i];
    }

    return max_profit;
}

//Method 2: // Buy and Sell a Share at most twice
int maxProfit3(vector<int>& prices) {
    int buy1 = INT_MAX, buy2 = INT_MAX;
    int sell1 = 0, sell2 = 0;
    for (int price : prices) {
          // the maximum profit if only one transaction is allowed
          buy1 = min(buy1, price);
          sell1 = max(sell1, price - buy1);
          // re-invest the gained profit in the second transaction
          buy2 = min(buy2, price - sell1);
          sell2 = max(sell2, price - buy2);
      }
      return sell2;
   }

//Buy and Sell Stock:4
int maxProfit4(int k, vector<int>& prices) {

   if (k >= prices.size() / 2) { // if k >= n/2, then you can make maximum number of transactions
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        return profit;
    }
   vector<int> buy(k+1,INT_MAX);
   vector<int> sell(k + 1,0);

    for (int price : prices) {
        for (int i = 1; i <= k; i++) {
            buy[i] = min(buy[i], price-sell[i - 1]);
            sell[i] = max(sell[i], price-buy[i]);
        }
    }
    return sell[k];
}

//Buy and sell stock with cooldown period
int maxProfit(vector<int>& prices) {
      int buy(INT_MAX), sell(0), prev_sell(0), prev_buy;
      for (int price : prices) {
          prev_buy = buy;
          buy = min(buy,price-prev_sell);
          prev_sell = sell;
          sell = max(sell,price-prev_buy);
      }
      return sell;
}

//Buy and Sell with transaction fee

int maxProfit(vector<int>& prices, int fee) {
      long buy(INT_MAX), sell(0), prev_sell(0), prev_buy;
  for (int price : prices) {
      buy = min(buy,price-sell);
      sell = max(sell,price-buy-fee);
  }
  return sell;
}
