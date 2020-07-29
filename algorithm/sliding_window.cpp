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

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>s;
        vector<int>ans;
        int ma=nums[0];
        int n=nums.size();
        for(int i=0;i<k;i++){
            ma=max(ma,nums[i]);
            s.insert(nums[i]);
        }
        ans.push_back(ma);
        for(int i=1;i<n-k+1;i++){
            s.erase(s.find(nums[i-1]));
            s.insert(nums[i+k-1]);
            ans.push_back(*s.rbegin());
        }
        return ans;
        
        
    }