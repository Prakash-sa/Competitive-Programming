//https://practice.geeksforgeeks.org/problems/minimum-swaps/1



class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<pair<int,int>>ans(n);
	    for(int i=0;i<n;i++){
	        ans[i]={nums[i],i};
	    }
	    sort(ans.begin(),ans.end());
	    int swap1=0;
	    for(int i=0;i<n;i++){
	        if(ans[i].second!=i){
	            swap1++;
	            swap(ans[i],ans[ans[i].second]);
	            i--;
	        }
	    }
	    return swap1;
	}
};
