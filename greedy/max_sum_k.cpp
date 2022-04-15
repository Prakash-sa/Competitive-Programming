//https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1#



class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        long long int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]<0 && k>0){
                a[i]=-a[i];
                k--;
            }
        }
        long long int minx=INT_MAX;
        for(int i=0;i<n;i++){
            minx=min(minx,a[i]);
            ans+=a[i];
        }
        if(k>0 && k%2!=0)ans-=minx*2;
        return ans;
    }
};
