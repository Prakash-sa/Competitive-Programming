//https://leetcode.com/problems/minimum-moves-to-equal-array-elements/


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



