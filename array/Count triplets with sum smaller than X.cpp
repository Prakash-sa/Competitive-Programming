//https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1#



class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    long long cnt=0;
	    for(int i=0;i<n;i++){
	        int j=i+1,k=n-1;
	        while(j<=k){
	            long long tmp=arr[i]+arr[j]+arr[k];
	            if(sum>tmp){
	                cnt+=k-j;
	                j++;
	            }
	            else k--;
	        }
	    }
	    return cnt;
	}
		 

};
