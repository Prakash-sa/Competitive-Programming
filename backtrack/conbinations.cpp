//https://leetcode.com/problems/combinations/



vector<vector<int>>res;

void ch(int n,int k,vector<int>&v){
    if(k==0){
        res.push_back(v);
        return;
    }
    if(k==n){
        v.push_back(n);
        ch(n-1,k-1,v);
        v.pop_back();
    }
    else if(n>k){
        ch(n-1,k,v);
        v.push_back(n);
        ch(n-1,k-1,v);
        v.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<int>v;
    ch(n,k,v);
    return res;
}
