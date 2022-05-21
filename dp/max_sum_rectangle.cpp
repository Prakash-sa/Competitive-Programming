//https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1




class Solution {
    
    int kadane(vector<int>&res){
        int lo=res[0],op=res[0];
        for(int i=1;i<res.size();i++){
            lo=max(res[i],res[i]+lo);
            op=max(lo,op);
        }
        return op;
    }
    
    
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        
        int ans=INT_MIN;
        for(int i=0;i<R;i++){
            vector<int>res(C,0);
            for(int j=i;j<R;j++){
                for(int k=0;k<C;k++){
                    res[k]+=M[j][k];
                }
                ans=max(ans,kadane(res));
            }
        }
        return ans;
    }
};
