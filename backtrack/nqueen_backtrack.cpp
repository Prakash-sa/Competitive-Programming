
void init(vector<int>adj[],int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)adj[i][j]=0;
    }
}

bool issafe(vector<int>adj[],int row,int s,int n){
    int i,j;
    
    for(i=0;i<n;i++)
    if(adj[row][i])return false;
    for(i=0;i<n;i++)
    if(adj[i][s])return false;
    
    for(i=row,j=s;i>=0&&j>=0;i--,j--)if(adj[i][j])return false;
    
    for(i=row,j=s;i<n&&j>=0;i++,j--)if(adj[i][j])return false;
    
    for(i=row,j=s;i<n&&j<n;i++,j++)if(adj[i][j])return false;
    
    for(i=row,j=s;i>=0&&j<n;i--,j++)if(adj[i][j])return false;
    
    return true;
}

void nqueen(vector<int>adj[],int n,int col,vector<vector<int>>&vv)
{
    if(col==n){
        vector<int>h;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[j][i])h.push_back(j+1);
            }
        }
        vv.push_back(h);
        return ;
    }
    for(int i=0;i<n;i++){
        if(issafe(adj,i,col,n)){
            adj[i][col]=1;
            nqueen(adj,n,col+1,vv);
            adj[i][col]=0;
        }
    }   
}




int main()
 {
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int>b[n];
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++)b[i].push_back(0);
	}
	vector<vector<int>>ans;
    nqueen(b,n,0,ans);
    if(ans.size()==0)cout<<"-1"<<endl;
    else {
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"] ";
    }
	cout<<endl;
    }
	}
	return 0;
}

/*

N-Queens 1
*/

//https://leetcode.com/problems/n-queens/


class Solution {
    vector<vector<string>>res;
    
    bool isValid(vector<string>&Q,int n,int row,int col){
        //check if the column had a queen before.
        for(int i=0;i<row;i++)if(Q[i][col]=='Q')return false;
        //check if the 45° diagonal had a queen before.
        for(int i=row-1,j=col-1;i>=0 && j>=0; i--,j--)if(Q[i][j]=='Q')return false;
        //check if the 135° diagonal had a queen before.
        for(int i=row-1,j=col+1;i>=0&& j<n;i--,j++)if(Q[i][j]=='Q')return false;
        return true;
    }
    
    void backtrack(vector<string>&Q,int x,int n){
        
        if(x==n){
            res.push_back(Q);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isValid(Q,n,x,i)){
                Q[x][i]='Q';
                backtrack(Q,x+1,n);
                Q[x][i]='.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>ans(n,string(n,'.'));
        backtrack(ans,0,n);
        return res;
    }
};





/*

N-Queens 2

https://leetcode.com/problems/n-queens-ii/


1. Approach:-
Time Complexity:- O(N!)
Space Complexity:- O(N*N);
*/

class Solution {
    
    int cnt;
    
    bool isValid(vector<vector<bool>>&ans,int row,int col,int n){
        for(int i=0;i<row;i++)if(ans[i][col])return false;
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)if(ans[i][j])return false;
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)if(ans[i][j])return false;
        return true;
    }
    
    int backtrack(vector<vector<bool>>&ans,int x,int n){
        if(x==n)return ++cnt;
        for(int i=0;i<n;i++){
            if(isValid(ans,x,i,n)){
                ans[x][i]=true;
                cnt=backtrack(ans,x+1,n);
                ans[x][i]=false;
            }
        }
        return cnt;
    }
    
public:
    int totalNQueens(int n) {
        cnt=0;
        vector<vector<bool>>ans(n,vector<bool>(n,false));
        return backtrack(ans,0,n);
    }
};

/*
2. Approach:-

Time Complexity:- O(N!)
Space Complexity:- O(N)
*/


class Solution {
    
    int cnt;
    
    int backtrack(vector<bool>&col,vector<bool>&diag,vector<bool>&anti_diag,int x,int n){
        if(x==n)return ++cnt;
        for(int i=0;i<n;i++){
            if(!col[i] && !diag[x+i] && !anti_diag[x-i+n-1]){
                col[i] = diag[x+i] = anti_diag[x-i+n-1]=true;
                cnt=backtrack(col,diag,anti_diag,x+1,n);
                col[i] = diag[x+i] = anti_diag[x-i+n-1]=false;
            }
        }
        return cnt;
    }
    
public:
    int totalNQueens(int n) {
        cnt=0;
        vector<bool> col(n),diag(2*n-1),anti_diag(2*n-1);
        return backtrack(col,diag,anti_diag,0,n);
    }
};
