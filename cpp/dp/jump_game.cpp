//https://leetcode.com/problems/jump-game/
/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
//Jump Game 1


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        if(nums[0]==0)return false;
        int can=nums[0];
        for(int i=0;i<=can;i++){
            if(i>=n-1)return true;
            can=max(can,i+nums[i]);
        }
        return false;
    }
};



//https://leetcode.com/problems/jump-game-ii/
/*

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index
*/
//Jump Game 2

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        for(int i = 1;i < n;i++){
            int minValue = INT_MAX;
            for(int j = i - 1;j >= 0;j--){
                if((i - j) <= nums[j]) minValue = min(minValue,res[j] + 1);
            }
            res[i] = minValue;
        }
        return res[n - 1];
    }
};



//https://leetcode.com/problems/jump-game-iii/
/*
Given an array of non-negative integers arr, 
you are initially positioned at start index of 
the array. When you are at index i,
you can jump to i + arr[i] or i - arr[i], 
check if you can reach to any index with value 0.


Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3
*/
//Jump Game 3



class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>visited(n,0);
        int i=start;
        queue<int>q;
        q.push(i);
        while(q.size()){
            i=q.front();
            q.pop();
            if(visited[i])continue;
            visited[i]=1;
            if(arr[i]==0)return true;
            int l=i-arr[i];
            int r=i+arr[i];
            if(l>=0)q.push(l);
            if(r<n)q.push(r);
        }
        return false;
        
    }
};



//https://leetcode.com/problems/jump-game-iv/
/*
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

    i + 1 where: i + 1 < arr.length.
    i - 1 where: i - 1 >= 0.
    j where: arr[i] == arr[j] and i != j.

Return the minimum number of steps to reach the last index of the array.

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

*/
//Jump Game 4


class Solution {
public:
    int minJumps(vector<int>& arr) {
        int step=0;
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vector<int>visited(n,0);
        visited[0]=1;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int i=q.front();
                q.pop();
                if(i==n-1)return step;
                vector<int>&next=mp[arr[i]];
                next.push_back(i+1);
                next.push_back(i-1);
                for(auto j:next){
                    if(j>=0 && j<n && !visited[j]){
                        visited[j]=1;
                        q.push(j);
                    }
                }
                next.clear();
            }
            step++;
        }
        return 0;
    }
};



//https://leetcode.com/problems/jump-game-v/
/*
Given an array of integers arr and an integer d. In one step you can jump from index i to index:

    i + x where: i + x < arr.length and 0 < x <= d.
    i - x where: i - x >= 0 and 0 < x <= d.

In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
Similarly You cannot jump from index 3 to index 2 or index 1.
*/
//Jump Game 5


class Solution {
    vector<int> dp;
    int n;
    
    int solve(vector<int>&arr,int x,int d){
        if(dp[x]!=-1)return dp[x];
        dp[x]=0;
        for(int i=x+1;i<=x+d && i<n && arr[i]<arr[x] ;i++){
            dp[x]=max(dp[x],1+solve(arr,i,d));
        }
        for(int i=x-1;i>=x-d && i>=0 && arr[i]<arr[x] ;i--){
            dp[x]=max(dp[x],1+solve(arr,i,d));
        }
        return dp[x];
    }
    
public:
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        dp.resize(n,-1);
        int result=0;
        for(int i=0;i<n;i++){
            result=max(result,1+solve(arr,i,d));
        }
        return result;
    }
};





//https://leetcode.com/problems/jump-game-vi/

/*
Jump Game 6

In Decreasing Deque approach:

We used a deque to store indices of nums elements, elements is in decreasing order, the front is the maximum element.
When adding a new number nums[i], we eliminate elements which is less or equal to nums[i] in deque, which will never be chosen in the future.
Push index of current nums[i] to back of the deque.
If the last element in deque is out of range K then remove it.
*/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int>q;
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        q.push_back(0);
        for(int i=1;i<n;i++){
            if(q.front()<i-k)q.pop_front();
            dp[i]=nums[i]+dp[q.front()];
            while(!q.empty() && dp[q.back()]<=dp[i])q.pop_back();
            q.push_back(i);
        }
        return dp[n-1];
    }
};





//https://leetcode.com/problems/jump-game-vii/
/*
You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

    i + minJump <= j <= min(i + maxJump, s.length - 1), and
    s[j] == '0'.

Return true if you can reach index s.length - 1 in s, or false otherwise.

Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.
*/
//Jump Game 7


class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1')return false;
        vector<int>dp(n,false);
        dp[0]=true;
        int pre=0;
        for(int i=1;i<n;i++){
            if(i>=minJump)pre+=dp[i-minJump];
            if(i>maxJump)pre-=dp[i-maxJump-1];
            dp[i]=pre>0 && s[i]=='0';
        }
        return dp[n-1];
    }
};


