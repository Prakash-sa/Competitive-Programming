//https://practice.geeksforgeeks.org/problems/array-removals/1/

/*
Given an array arr[] of size N and an integer K. The task is to find the minimum number of elements that should be removed, such that Amax-Amin<=K. 
After the removal of elements, Amax and Amin is considered among the remaining elements. 
Note: Can you solve the probelm without using any extra space and O(N*log(N)) time complexity ?

Example 1:

Input: N = 9, K = 4  
arr[] = {1,3,4,9,10,11,12,17,20}
Output: 5
*/


class Solution{
    public:
    int removals(vector<int>& a, int k){
        //Code here
        int maxLen=1;
        sort(a.begin(),a.end());
        int i=0,j=1;
        int n=a.size();
        while(j<n && i<n){
            if(a[j]-a[i]<=k){
                maxLen=max(maxLen,j-i+1);
                j++;
            }
            else {
                i++;
                j=i+1;
            }
        }
        return n-maxLen;
    }
};

