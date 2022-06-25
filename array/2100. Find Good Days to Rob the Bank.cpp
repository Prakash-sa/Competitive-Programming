//https://leetcode.com/problems/find-good-days-to-rob-the-bank/




class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int>res;
        int n=security.size();
        vector<int>left(n,0),right(n,0);
        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1])left[i]=1+left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(security[i+1]>=security[i])right[i]=1+right[i+1];
        }
        for(int i=0;i<n;i++){
            if(left[i]>=time && right[i]>=time)res.push_back(i);
        }
        return res;
    }
};
