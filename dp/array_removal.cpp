//https://practice.geeksforgeeks.org/problems/array-removals/1/



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

