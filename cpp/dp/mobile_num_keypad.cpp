//https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1#



class Solution{


	public:
	long long getCount(int N)
	{
		// Your code goes here
		
	    vector<vector<int>> data = {{0,8},
	                                {1,2,4},
	                                {1,2,3,5},
	                                {2,3,6},
	                                {1,4,5,7},
	                                {2,4,5,8,6},
	                                {3,5,6,9},
	                                {4,7,8},
	                                {5,8,0,7,9},
	                                {8,6,9}};
	                                                        
		vector<vector<long long>> dp(N+1,vector<long long>(10,0));
		
		
		for(int i=0;i<10;i++){
		    dp[1][i]=1;
		}
		
		for(int i=2;i<=N;i++){
		    for(int j=0;j<10;j++){
		        for(auto x:data[j]){
		            dp[i][x]+=dp[i-1][j];
		        }
		    }
		}
		
		long long ans = 0;
		for(auto x:dp.back())ans+=x;
		return ans;
	}


};
