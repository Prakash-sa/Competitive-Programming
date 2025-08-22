//https://practice.geeksforgeeks.org/problems/geek-and-his-binary-strings1951/1/#


class Solution{

	public:
	int prefixStrings(int N)
	{
	    // Your code goes here
	    vector<long long> t(N+1,0);
        t[0]=t[1]=1;
        int mod=1000000007;
        for(int i=2;i<=N;i++){
            for(int j=0;j<i;j++){
                t[i]+=((t[j]%mod)*(t[i-j-1]%mod))%mod;
            }
        }
        return t[N]%mod;
	}

};
