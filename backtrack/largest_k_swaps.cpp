//https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#


    
    void backtrack(string str,string &maxs,int start,int k)
    {
        if(k==0){
            return;
        }
        int n=str.size();
        char maxi=str[start];
        
        for(int i=start+1;i<n;i++){
            if(maxi<str[i])maxi=str[i];
        }
        
        if(maxi!=str[start])k--;
        
        
        for(int i=n-1;i>=start;i--){
            if(str[i]==maxi){
                swap(str[i],str[start]);
                if(str.compare(maxs)>0)maxs=str;
                backtrack(str,maxs,start+1,k);
                swap(str[i],str[start]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string maxs=str;
       backtrack(str,maxs,0,k);
       return maxs;
       
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
