//https://leetcode.com/contest/weekly-contest-187/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

int longestSubarray(vector<int>& nums, int limit) {
    int n=nums.size();
    int ans=0,j=0;
    multiset<int>cnt;
    for(int i=0;i<n;i++){
        cnt.insert(nums[i]);
        while(*cnt.rbegin()-*cnt.begin()>limit){
            cnt.erase(cnt.find(nums[j++]));
        }
        ans=max(ans,i-j+1);
    }
    return ans;
}