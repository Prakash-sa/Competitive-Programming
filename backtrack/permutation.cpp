//https://www.interviewbit.com/problems/permutations/

void backtrack(vector<int>&A,vector<vector<int>>&res,int in){
    if(in==A.size()){
        res.push_back(A);
        return;
    }
    for(int i=in;i<A.size();i++){
        swap(A[i],A[in]);
        backtrack(A,res,in+1);
        swap(A[i],A[in]);
    }
    return ;
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>>res;
    backtrack(A,res,0);
    return res;
}




//https://leetcode.com/problems/permutations-ii/


class Solution {
    
    vector<vector<int>> ans;
    
    void backtrack(vector<int>&nums,int x){
        if(x==nums.size()){
            ans.push_back(nums);
            return ;
        }
        unordered_set<int>s;
        for(int i=x;i<nums.size();i++){
            if(s.find(nums[i])!=s.end())continue;
            s.insert(nums[i]);
            swap(nums[i],nums[x]);
            backtrack(nums,x+1);
            swap(nums[i],nums[x]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums,0);
        return ans;
    }
};




