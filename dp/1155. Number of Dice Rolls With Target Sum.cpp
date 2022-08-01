//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

/*
We can define our dp[i][k] as number of ways we can get k using i dices. 
As an initial point, there is one way to get to 0 using zero dices.
Then, for each dice i and face j, accumulate the number of ways we can get to k.

You have n dice and each die has k faces numbered from 1 to k.
Given three integers n, k, and target, return the number of possible ways 
(out of the kn total ways) to roll the dice so the sum of the face-up numbers equals target. 
Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1

Coin Change


Runtime: O(d * f * target).
Memory: O(d * target) for the memoisation.

Bottom-Up DP

We can define our dp[i][k] as number of ways we can get k using i dices. As an initial point, there is one way to get to 0 using zero dices.
Then, for each dice i and face j, accumulate the number of ways we can get to k.
Note that for the bottom-up solution, we can reduce our memory complexity as we only need to store counts for the previous dice.
*/


class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int>dp(target+1,0);
        long int mod=1e9+7;
        dp[0]=1;
        for(int i=1;i<=n;i++){
            vector<int>dp1(target+1);
            for(int j=1;j<=k;j++){
                for(int l=j;l<=target;l++){
                    dp1[l]=(dp1[l]+dp[l-j])%mod;
                }
            }
            swap(dp,dp1);
        }
        return dp[target];
    }
};

