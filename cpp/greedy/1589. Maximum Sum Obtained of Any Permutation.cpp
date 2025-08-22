//https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/

//We should put the largest number into the most queried position.


class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<int>count(n,0);
        for(auto it:requests){
            count[it[0]]+=1;
            if(it[1]+1<n)count[it[1]+1]-=1;
        }
        for(int i=1;i<n;i++)count[i]+=count[i-1];
        sort(count.begin(),count.end());
        sort(nums.begin(),nums.end());
        long ans=0;
        long int modi=1e9+7;
        for(int i=0;i<n;i++){
            ans+=(long)count[i]*nums[i];
        }
        
        return ans%modi;
    }
};
