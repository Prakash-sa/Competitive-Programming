/*
https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/
You are given two 0-indexed arrays nums and cost consisting each of n positive integers.
You can do the following operation any number of times:
Increase or decrease any element of the array nums by 1.
The cost of doing one operation on the ith element is cost[i].
Return the minimum total cost such that all the elements of the array nums become equal.

Example 1:
Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.

Example 2:
Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
Output: 0
Explanation: All the elements are already equal, so no operations are needed.
*/

class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        long long l = 1, r = 1000000, res = f(nums, cost, 1), x;
        while (l < r)
        {
            x = (l + r) / 2;
            long long y1 = f(nums, cost, x), y2 = f(nums, cost, x + 1);
            res = min(y1, y2);
            if (y1 < y2)
                r = x;
            else
                l = x + 1;
        }
        return res;
    }

    long long f(vector<int> &A, vector<int> &cost, int x)
    {
        long long res = 0;
        for (int i = 0; i < A.size(); i++)
        {
            res += 1l * abs(A[i] - x) * cost[i];
        }
        return res;
    }
};