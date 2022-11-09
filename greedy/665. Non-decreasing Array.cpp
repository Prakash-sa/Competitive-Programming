// https://leetcode.com/problems/non-decreasing-array/

/*
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).



Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
*/

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        bool first = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                if (!first)
                    return false;
                first = false;
                if (i > 0 && nums[i - 1] > nums[i + 1])
                    nums[i + 1] = nums[i];
            }
        }
        return true;
    }
};
