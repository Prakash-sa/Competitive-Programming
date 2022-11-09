// https://leetcode.com/problems/count-of-range-sum/

/*
Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.



Example 1:
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.

Example 2:
Input: nums = [0], lower = 0, upper = 0
Output: 1
*/

class Solution
{
public:
    int mergeSort(vector<long> &pre, int l, int h, int lower, int upper)
    {
        if (h <= 1 + l)
            return 0;
        int mid = (l + h) / 2;
        int n = mid, m = mid;
        int sum = mergeSort(pre, l, mid, lower, upper) + mergeSort(pre, mid, h, lower, upper);
        for (int i = l; i < mid; i++)
        {
            while (m < h && pre[m] - pre[i] < lower)
                m++;
            while (n < h && pre[n] - pre[i] <= upper)
                n++;
            sum += n - m;
        }
        inplace_merge(pre.begin() + l, pre.begin() + mid, pre.begin() + h);
        return sum;
    }

    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        vector<long> pre(nums.size() + 1, 0);
        pre[0] = 0;
        for (int i = 0; i < nums.size(); i++)
            pre[i + 1] = pre[i] + nums[i];
        // return mergeSort1(pre,lower,upper,0,nums.size()+1);
        return mergeSort(pre, 0, nums.size() + 1, lower, upper);
    }
};
