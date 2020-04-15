int findMaxLength(vector<int>& nums) {
    for(int i=0;i<nums.size();i++)if(nums[i]==0)nums[i]=-1;
    unordered_map<int,int>mp;
    int sum=0,maxlen=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==0)maxlen=i+1;
        if(mp.find(sum)!=mp.end()){
            maxlen=max(maxlen,i-mp[sum]);
        }
        else {
            mp[sum]=i;
        }
    }
    return maxlen;      
}
