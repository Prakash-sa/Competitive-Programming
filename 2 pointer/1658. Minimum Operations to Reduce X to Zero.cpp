//https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

//https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/discuss/2136570/Change-Your-Perspective-or-JAVA-Explanation

/*
You are given an integer array nums and an integer x. 
In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. 
Note that this modifies the array for future operations.
Return the minimum number of operations to reduce x to exactly 0 if it is possible, 
otherwise, return -1.
*/





class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(begin(nums), end(nums), 0);
        int l = 0, r = 0, res = INT_MAX, sz = nums.size();
        while (l <= r){
            if (sum >= x) {
                if (sum == x)
                    res = min(res, l + sz - r);
                if (r < sz)
                    sum -= nums[r++];
                else
                    break;
            }
            else
                sum += nums[l++];
        }
        return res == INT_MAX ? -1 : res;
    }
};


