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


//https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/0/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;

void init(){

}

 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       int n,k;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++)cin>>a[i];
       cin>>k;
       int cnt=0,ans=INT_MAX;
       for(int i=0;i<n;i++){
           if(a[i]<=k)cnt++;
       }
       for(int i=0;i<n-cnt+1;i++){
           int bad=0;
           for(int j=i;j<i+cnt;j++)if(a[j]>k)bad++;
           //cout<<bad<<" ";
           ans=min(ans,bad);
       }
       cout<<ans<<endl;
   }
   
   return 0;
}