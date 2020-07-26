
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