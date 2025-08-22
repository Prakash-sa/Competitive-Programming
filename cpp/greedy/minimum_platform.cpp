//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
        sort(arr,arr+n);
        sort(dep,dep+n);
        int cnt=0,end=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]<=dep[end]){
                cnt++;
            }
            else end++;
        }
        return cnt;
    }
    
};
