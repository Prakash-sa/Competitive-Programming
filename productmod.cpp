/*fi(nums) = nums[0] · nums[1] · ... · nums[i - 1] · nums[i + 1] · ... · nums[n - 1].
(In other words, fi(nums) is the product of all array elements except the ithf.)
g(nums) = f0(nums) + f1(nums) + ... + fn-1(nums).
*/

int productExceptSelf(std::vector<int> nums, int m) {
    int n=nums.size();
    int pre[n]={1};
    pre[0]=nums[0];
    for(int i=1;i<n;i++)pre[i]=pre[i-1]*nums[i]%m;
    int suf[n]={1},ans[n]={0};
    suf[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--)suf[i]=suf[i+1]*nums[i]%m;
    ans[0]=suf[1];
    ans[n-1]=pre[n-2];
    for(int i=1;i<n-1;i++){
        ans[i]=pre[i-1]*suf[i+1]%m;
    }
    int ns=nums.size();
    int g=0;
    for(int i=0;i<ns;i++)g=(g+ans[i])%m;
    return g;
}
