//https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1/#



class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      int ans=INT_MAX;
      int sum=0;
      for(int i=0;i<a.size();i++){
          sum=min(a[i],sum+a[i]);
          ans=min(sum,ans);
      }
      
      return ans;
  }
};
