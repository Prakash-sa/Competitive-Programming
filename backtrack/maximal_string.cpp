//https://www.interviewbit.com/problems/maximal-string/
void backtrack(string A,string &ans,int b){
    if(b==0)return;
    for(int i=0;i<A.size()-1;i++){
        for(int j=i+1;j<A.size();j++){
            if(A[j]>A[i]){
                swap(A[j],A[i]);
                if(A>ans)ans=A;
                backtrack(A,ans,b-1);
                swap(A[j],A[i]);
            }
        }
    }
    return ;
}

string Solution::solve(string A, int B) {
    string ans="";
    backtrack(A,ans,B);
    return ans;
}
