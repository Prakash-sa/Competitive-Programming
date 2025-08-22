class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return {};
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>pre_node(n,-1);
        int max_in=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    pre_node[i]=j;
                }
            }
            if(dp[i]>dp[max_in])max_in=i;
        }
        vector<int>ans;
        int t=max_in;
        while(t>=0){
            ans.push_back(nums[t]);
            t=pre_node[t];
        }
        return ans;
    }
};