//https://www.interviewbit.com/problems/maximal-string/
//https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#
/*
Given a number K and string str of digits denoting a positive integer, 
build the largest number possible by performing swap operations on the digits of str at most K times.
*/

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


//easy 

string ans;
int n;

void check(int x,string &str,int k){
    if(ans<str)ans=str;
    if(k==0 || x==n)return;
    check(x+1,str,k);

    for(int i=x+1;i<n;i++){
        if(str[i]>str[x]){
            swap(str[i],str[x]);
            check(x+1,str,k-1);
            swap(str[i],str[x]);
        }
    }
}

string Solution::solve(string A, int B) {
    ans=A;
    n=A.size();
    check(0,A,B);
    return ans;
}
