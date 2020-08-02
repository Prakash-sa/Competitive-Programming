
int label[1000];
int adj[1000][1000];

bool dfs(int v,int cnt,int n){
    if(cnt==n)return true;
    for(int i=0;i<n;i++){
            if(adj[v][i]&&(label[i]==0)){
                label[i]=1;
                if(dfs(i,cnt+1,n))return true;
                label[i]=0;
            }
    }
    return false;
}

bool check_using_dfs(int n){
    for(int i=0;i<n;i++)label[i]=0;
    for(int i=0;i<n;i++){
        label[i]=1;
        if(dfs(i,1,n))return true;
        label[i]=0;
    }
    return false;
}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)adj[i][j]=0;
	for(int i=0;i<m;i++){
	    int x1,x2;
	    cin>>x1>>x2;
	    adj[x1-1][x2-1]=1;
	    adj[x2-1][x1-1]=1;
	}
	
	if(check_using_dfs(n))cout<<"1"<<endl;
	else cout<<"0"<<endl;
	
	
	}
	return 0;
}