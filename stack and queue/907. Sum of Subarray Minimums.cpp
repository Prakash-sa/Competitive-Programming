/*
https://leetcode.com/problems/sum-of-subarray-minimums/description/

https://www.youtube.com/watch?v=Ulb3ixSpE4Y


Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
*/

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        stack<pair<int, int>> st_left, st_right;
        vector<int> left(n), right(n);
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            while (!st_left.empty() && st_left.top().first > arr[i])
            {
                cnt += st_left.top().second;
                st_left.pop();
            }
            left[i] = cnt;
            st_left.push({arr[i], cnt});
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int cnt = 1;
            while (!st_right.empty() && st_right.top().first >= arr[i])
            {
                cnt += st_right.top().second;
                st_right.pop();
            }
            right[i] = cnt;
            st_right.push({arr[i], cnt});
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % mod;
        }
        return ans;
    }
};