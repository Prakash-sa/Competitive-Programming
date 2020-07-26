//https://www.interviewbit.com/problems/permutations/

void backtrack(vector<int>&A,vector<vector<int>>&res,int in){
    if(in==A.size()){
        res.push_back(A);
        return;
    }
    for(int i=in;i<A.size();i++){
        swap(A[i],A[in]);
        backtrack(A,res,in+1);
        swap(A[i],A[in]);
    }
    return ;
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>>res;
    backtrack(A,res,0);
    return res;
}
