//https://leetcode.com/problems/count-of-range-sum/

class Solution {
public:
    
    int mergeSort(vector<long> &pre,int l,int h,int lower,int upper){
        if(h<=1+l)return 0;
        int mid=(l+h)/2;
        int n=mid,m=mid;
        int sum=mergeSort(pre,l,mid,lower,upper)+mergeSort(pre,mid,h,lower,upper);
        for(int i=l;i<mid;i++){
            while(m<h && pre[m]-pre[i]<lower)m++;
            while(n<h && pre[n]-pre[i]<=upper)n++;
            sum+=n-m;
        }
        inplace_merge(pre.begin()+l,pre.begin()+mid,pre.begin()+h);
        return sum;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long>pre(nums.size()+1,0);
        pre[0]=0;
        for(int i=0;i<nums.size();i++)pre[i+1]=pre[i]+nums[i];
        //return mergeSort1(pre,lower,upper,0,nums.size()+1);
        return mergeSort(pre,0,nums.size()+1,lower,upper);
    }
};
