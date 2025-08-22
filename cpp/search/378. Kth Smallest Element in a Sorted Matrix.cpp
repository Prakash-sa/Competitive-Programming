//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n2). 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
*/


class Solution {
    
    int countElement(vector<vector<int>>&matrix,int mid){
        int cnt=0,j=matrix[0].size()-1;
        for(int i=0;i<matrix.size();i++){
            while(j>=0 && matrix[i][j]>mid)j--;
            cnt+=j+1;
        }
        return cnt;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        int l=matrix[0][0],r=matrix[n-1][m-1],ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(countElement(matrix,mid)>=k){
                ans=mid;
                r=mid-1;
            }    
            else l=mid+1;
        }
        return ans;
    }
};