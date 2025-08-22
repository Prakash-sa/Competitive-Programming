//longest_sum_contiguous_subarray
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int ch(int a[],int n){
    int lo=a[0],go=a[0];
    for(int i=1;i<n;i++){
        lo=max(a[i],a[i]+lo);
        go=max(go,lo);
    }
    return go;
}

int main()
{
    speed;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<ch(a,n)<<endl;
    }


    return 0;
}

//for multiply --------------

int maxProduct(vector<int>& nums) {
    int ans=nums[0],maxm=nums[0],minm=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]<0){
            swap(maxm,minm);
        }
        maxm=max(nums[i],nums[i]*maxm);
        minm=min(nums[i],nums[i]*minm);
        ans=max(ans,maxm);
    }
    return ans;
    
}