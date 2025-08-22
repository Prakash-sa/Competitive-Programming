//https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

/*
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
In one move, you can increment n - 1 elements of the array by 1.

 

Example 1:

Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0,minn=INT_MAX;
        int n=nums.size();
        for(auto it:nums){
            sum+=it;
            minn=min(minn,it);
        }
        return sum-minn*(n);
        
    }
};


//https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

/*
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
In one move, you can increment or decrement an element of the array by 1.
Test cases are designed so that the answer will fit in a 32-bit integer.
 

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-nums[n/2]);
        }
        return ans;
    }
};



