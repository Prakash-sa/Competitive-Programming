/*
Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16
*/

class Solution {
    int mod=1e9+7;
    int helper(vector<int>&arr){
        int cnt=0;
        int prefix=0;
        int oddSum=0,evenSum=1;
        for(int i=0;i<arr.size();i++){
            prefix+=arr[i];
            if(prefix%2==0){
                cnt=(cnt+oddSum)%mod;
                evenSum++;
            }
            else {
                cnt=(cnt+evenSum)%mod;
                oddSum++;
            }
        }
        return cnt;
    }
public:
    int numOfSubarrays(vector<int>& arr) {
        return helper(arr);
    }
};
