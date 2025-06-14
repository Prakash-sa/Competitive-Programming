// Subset
// https://leetcode.com/problems/subsets/description/

class Solution {
    vector<vector<int>>res;

    void backtrack(vector<int>&nums, int x,vector<int>&tmp){
        res.push_back(tmp);
        for(int i=x;i<nums.size();i++){
            tmp.push_back(nums[i]);
            backtrack(nums,i+1,tmp);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>tmp;
        backtrack(nums,0,tmp);
        return res;
    }
};

// Subset 2
// https://leetcode.com/problems/subsets-ii/description/


class Solution {
    vector<vector<int>>res;

    void backtrack(vector<int>&nums, int x,vector<int>&tmp){
        res.push_back(tmp);
        for(int i=x;i<nums.size();i++){
            if(i>x && nums[i]==nums[i-1])continue; // to remove duplicates
            tmp.push_back(nums[i]);
            backtrack(nums,i+1,tmp);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>tmp;
        backtrack(nums,0,tmp);
        return res;
    }
};

// Permutations
// https://leetcode.com/problems/permutations/description/


class Solution {
    vector<vector<int>>res;

    void backtrack(vector<int>&nums,int in){
        if(in==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=in;i<nums.size();i++){
            swap(nums[i],nums[in]);
            backtrack(nums,in+1);
            swap(nums[i],nums[in]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }
};

// https://leetcode.com/problems/permutations-ii/description/
// return unique permutations

class Solution {
    vector<vector<int>>res;

    void backtrack(vector<int>&nums,int index){
        if(index==nums.size()){
            res.push_back(nums);
            return ;
        }

        // to store the uniqueness
        unordered_set<int>st;
        for(int i=index;i<nums.size();i++){
            if(st.find(nums[i])!=st.end())continue;
            st.insert(nums[i]);
            swap(nums[index],nums[i]);
            backtrack(nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }
};

// https://leetcode.com/problems/palindrome-partitioning/description/

/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
*/

class Solution {
    vector<vector<string>>res;

    bool isPalindrome(string s){
        string tmp=s;
        reverse(tmp.begin(),tmp.end());
        return tmp==s;
    }

    void backtrack(string s,int index,vector<string>&arr){
        if(index==s.size()){
            res.push_back(arr);
            return;
        }

        for(int i=index;i<s.size();i++){
            string tmp=s.substr(index,i-index+1);
            if(isPalindrome(tmp)){
                arr.push_back(tmp);
                backtrack(s,i+1,arr);
                arr.pop_back();
            }
        }

    }

public:
    vector<vector<string>> partition(string s) {
        vector<string>arr;
        backtrack(s,0,arr);
        return res;
    }
};
