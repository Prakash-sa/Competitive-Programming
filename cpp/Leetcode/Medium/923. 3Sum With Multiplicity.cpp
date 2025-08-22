
/*
https://leetcode.com/problems/3sum-with-multiplicity/

Count the occurrence of each number.
using hashmap or array up to you.

Loop i on all numbers,
loop j on all numbers,
check if k = target - i - j is valid.

Add the number of this combination to result.
3 cases covers all possible combination:

    i == j == k
    i == j != k
    i < k && j < k

Time Complexity:
3 <= A.length <= 3000, so N = 3000
But 0 <= A[i] <= 100
So my solution is O(N + 101 * 101)
*/




class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,long>mp;
        for(auto it:arr){
            mp[it]++;
        }
        long int modu=1e9+7;
        long ans=0;
        long tmp=0;
        for(auto it:mp){
            for(auto it2:mp){
                int i=it.first;
                int j=it2.first;
                int k=target-i-j;
                if(!mp.count(k))continue;
                tmp=0;
                if(i==j&&j==k){
                    tmp=mp[i]*(mp[i]-1)*(mp[i]-2)/6;  
                }
                else if(i==j&&j!=k){
                    tmp=mp[i]*(mp[i]-1)/2*mp[k];
                }
                else if(i<j && j<k){
                    tmp=mp[i]*mp[j]*mp[k];
                }
                ans=(ans+tmp);
            }
        }
        return ans%modu;
    }
};
