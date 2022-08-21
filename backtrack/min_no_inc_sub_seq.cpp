#include<bits/stdc++.h>
using namespace std;


//https://www.geeksforgeeks.org/minimum-number-of-increasing-subsequences/


int ch(int a[],int n){
  multiset<int>last;
  for(int i=0;i<n;i++){
    auto it=last.lower_bound(a[i]);
    if(it==last.begin())last.insert(a[i]);
    else {
      it--;
      last.erase(it);
      last.insert(a[i]);
    }
  }
  return last.size();
}

int main(){
  int t;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<ch(a,n)<<endl;
  }
}


//https://leetcode.com/problems/increasing-subsequences/



class Solution {

    set<vector<int>>res;
    int n;
    
    void backtrack(int x,vector<int>&nums,vector<int>&a){
        if(a.size()>1)
            res.insert(a);   
        for(int i=x;i<n;i++){
            if(a.size()==0 || nums[i]>=a.back()){
                a.push_back(nums[i]);
                backtrack(i+1,nums,a);
                a.pop_back();
            }
        }
    }
    
    public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<int>a;
        backtrack(0,nums,a);
        vector<vector<int>>ans(res.begin(),res.end());
        return ans;
    }
};