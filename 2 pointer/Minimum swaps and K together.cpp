//https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1#




class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int ans=0;
        int cnt=0;
        int bad=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k)cnt++;
        }
        for(int i=0;i<cnt;i++)if(arr[i]>k)bad++;
        ans=bad;
        for(int i=0,j=cnt;j<n;j++,i++){
            if(arr[i]>k)bad--;
            if(arr[j]>k)bad++;
            ans=min(ans,bad);
        }
        return ans;
    }
};
