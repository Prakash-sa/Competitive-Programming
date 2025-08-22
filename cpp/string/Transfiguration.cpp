//https://practice.geeksforgeeks.org/problems/b6b3297ccfb1ad5f66a9c2b92979170417adf114/1/#





class Solution{
    
    public:
    int transfigure (string &A, string &B)
    {
    	// Your code goes here
    	unordered_map<char,int>mp;
    	for(auto it:A)mp[it]++;
    	for(auto it:B){
    	    mp[it]--;
    	    if(mp[it]<0)return -1;
    	}
    	int n=A.size();
    	int i=n-1,j=n-1;
    	int res=0;
    	while(i>=0 && j>=0){
    	   if(A[i]!=B[j]){
    	       i--;
    	       res++;
    	   }
    	   else{
    	       i--;
    	       j--;
    	   }
    	}
    	return res;
    }
};
