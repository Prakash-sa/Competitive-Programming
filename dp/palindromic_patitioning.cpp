//Palindrome Partitioning 1
//https://leetcode.com/problems/palindrome-partitioning/


class Solution {
    
    vector<vector<string>>ans;
    
    bool isPalin(string s){
        string tmp=s;
        reverse(tmp.begin(),tmp.end());
        return tmp==s;
    }
    
    void backtrack(string &s,int pos,vector<string>&path){
        if(pos>=s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=pos;i<s.size();i++){
            if(isPalin(s.substr(pos,i-pos+1))){
                path.push_back(s.substr(pos,i-pos+1));
                backtrack(s,i+1,path);
                path.pop_back();
            }
        }
    }
    
    
public:
    vector<vector<string>> partition(string s) {
        vector<string>path;
        backtrack(s,0,path);
        return ans;
    }
};



//Palindrome Partitioning 2

//https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

//https://leetcode.com/problems/palindrome-partitioning-ii/


class Solution {
    vector<vector<int>>dp1;
    vector<vector<int>>dp2;
    
    
    bool isPalin(int i,int j,string &s){
        if(i>=j)return true;
        if(dp1[i][j]!=-1)return dp1[i][j];
        if(s[i]==s[j])return dp1[i][j]=isPalin(i+1,j-1,s);
        return dp1[i][j]=false;
    }
    
    int solve(int start,int end,string &s){
        if(start>=end)return 0;
        if(isPalin(start,end,s))return 0;
        if(dp2[start][end]!=-1)return dp2[start][end];
        
        int cnt=INT_MAX;
        for(int i=start;i<=end;i++){
            if(isPalin(start,i,s))
            cnt=min(cnt,1+solve(i+1,end,s));
        }
        return dp2[start][end]=cnt;
    }
    
    
    
public:
    int minCut(string s) {
        int n=s.size();
        dp1.resize(n,vector<int>(n,-1));
        dp2.resize(n,vector<int>(n,-1));
        return solve(0,n-1,s);
        
    }
};



//Palindrome Partitioning 3
//https://leetcode.com/problems/palindrome-partitioning-iii/

class Solution {
    vector<vector<int>>cost;
    vector<vector<int>>dp;
    int inf=1e5;
    
    int nCost(int i,int j,string &s){
        if(i>=j)return 0;
        if(cost[i][j]!=-1)return cost[i][j];
        if(s[i]==s[j])return cost[i][j]=nCost(i+1,j-1,s);
        return cost[i][j]=1+nCost(i+1,j-1,s);
    }
    
    int solve(int start,int k,string &s){
        if(k==0)return nCost(start,s.size()-1,s);
        if(start==s.size())return inf;
        if(dp[start][k]!=-1)return dp[start][k];
        int cnt=inf;
        for(int i=start;i<s.size()-1;i++){
            cnt=min(cnt,nCost(start,i,s)+solve(i+1,k-1,s));
        }
        return dp[start][k]=cnt;
        
    }
    
public:
    int palindromePartition(string s, int k) {
        int n=101;
        cost.resize(n,vector<int>(n,-1));
        dp.resize(n,vector<int>(101,-1));
        return solve(0,k-1,s);
    }
};


//Palindrome Partitioning 4
//https://leetcode.com/problems/palindrome-partitioning-iv/



class Solution {
    
public:
    bool checkPartitioning(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j)dp[i][j]=1;
                else if(s[i]==s[j] && i+1==j){
                    dp[i][j]=1;
                }
                else if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(dp[0][i-1] && dp[i][j-1] && dp[j][n-1])return true;
            }
        }
        
        return false;
    }
};
