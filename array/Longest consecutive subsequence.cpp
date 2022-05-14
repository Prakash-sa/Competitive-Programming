//https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#





class Solution{
  public:
    
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      sort(arr,arr+N);
      int ans=1,cnt=1;
      for(int i=1;i<N;i++){
          if(arr[i]==arr[i-1]+1 )cnt++;
          else if(arr[i]!=arr[i-1])cnt=1;
          ans=max(ans,cnt);
      }
      return ans;
    }
};




//using hashmap


 

int findLongestConseqSubseq(int arr[], int N)
   {
       
       int temp[100000]={0};
       int maxIndex=0;
       for(int i=0;i<N;i++){
           temp[arr[i]]=1;
           maxIndex=max(maxIndex, arr[i]);
       }
       int maxCount=0; int count=0;
       for(int i=1;i<=maxIndex;i++){
           if(temp[i])
               count++;
           else
               count=0;
           maxCount=max(maxCount, count);
       }
       return maxCount;
   }
