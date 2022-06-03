//https://www.interviewbit.com/problems/combination-sum/
void backtrack(vector<int>A,vector<int>&path,vector<vector<int>>&res,int sum,int id){
    int n=A.size();
    if(sum<0)return ;
    if(sum==0){
        sort(path.begin(),path.end());
        auto it=find(res.begin(),res.end(),path);
        if(it==res.end())
        res.push_back(path);
        return;
    }
    for(int i=id;i<n;i++){
        if(sum+A[i]>=0){
            path.push_back(A[i]);
            backtrack(A,path,res,sum-A[i],i);
            path.pop_back();
        }
    }
    return ;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<int>path;
    vector<vector<int>>res;
    backtrack(A,path,res,B,0);
    sort(res.begin(),res.end());
    return res;
}




//https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1#

vector<vector<int>>res;
    
    void backtrack(vector<int>A,vector<int>&ans,int start,int sum){
        if(sum==0){
            res.push_back(ans);
            return ;
        }
        if(sum<0)return;
        
        for(int i=start;i<A.size();i++){
            if(i>start&&A[i]==A[i-1])continue;
            ans.push_back(A[i]);
            backtrack(A,ans,i,sum-A[i]);
            ans.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<int>ans;
        res.clear();
        sort(A.begin(),A.end());
        backtrack(A,ans,0,B);
        return res;
    }


/*
Combinations 

Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].


Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

//https://leetcode.com/problems/combinations/

class Solution {
    
    vector<vector<int>>res;
    
    
    void backtrack(int x,int n,int k,vector<int>&ans){
        if(ans.size()==k){
            res.push_back(ans);
            return;
        }
        
        for(int i=x;i<=n;i++){
            ans.push_back(i);
            backtrack(i+1,n,k,ans);
            ans.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        backtrack(1,n,k,ans);
        return res;
    }
};


/*
Combination Sum 1
Given an array of distinct integers candidates 
and a target integer target, return a list of all unique combinations 
of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from candidates 
an unlimited number of times. Two combinations 
are unique if the frequency of at least one of the chosen numbers is different.

*/

//https://leetcode.com/problems/combination-sum/


class Solution {
    vector<vector<int>>res;
    
    void backtrack(vector<int>&cand,int x,int target,vector<int>&a){
        if(target==0){
            res.push_back(a);
            return ;
        }
        if(x==cand.size())return;
        if(target<0)return;
        backtrack(cand,x+1,target,a);
        a.push_back(cand[x]);
        backtrack(cand,x,target-cand[x],a);
        a.pop_back();
        
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>a;
        backtrack(candidates,0,target,a);
        return res;
    }
};


/*
Combination Sum 2

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]


https://leetcode.com/problems/combination-sum-ii/


*/

class Solution {
    
    vector<vector<int>>res;
    
    void backtrack(vector<int>&cand,vector<int>&ans,int x,int target){
        if(target==0){
            res.push_back(ans);
            return;
        }
        if(target<0)return;
        if(x==cand.size())return;
        for(int i=x;i<cand.size();i++){
            if( i>x && cand[i]==cand[i-1])continue; //to avoid duplicates
            ans.push_back(cand[i]);
            backtrack(cand,ans,i+1,target-cand[i]);
            ans.pop_back();
        }
    }
    
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        backtrack(candidates,ans,0,target);
        return res;
    }
};


/*
Combination Sum 3
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

    Only numbers 1 through 9 are used.
    Each number is used at most once.

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7

https://leetcode.com/problems/combination-sum-iii/


*/


class Solution {
    vector<vector<int>>ans;
    
    void backtrack(vector<int>&path,int k,int n){
        if(n<0)return;
        if(path.size()==k && n==0){
            ans.push_back(path);
            return;
        }
        
        for(int i=path.size()==0?1:path.back()+1;i<=9;i++){
            if(n<0)break;
            path.push_back(i);
            backtrack(path,k,n-i);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int>path;
        backtrack(path,k,n);
        return ans;
    }
};


/*
Combination Sum 4

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.


https://leetcode.com/problems/combination-sum-iv/
*/


class Solution {
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unsigned int>dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(auto it:nums) if(i>=it)dp[i]+=dp[i-it];
        }
        return dp[target];
    }
};