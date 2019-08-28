//---------------------is cyclic for directed---------------------------//

bool iscyl(bool vis[],int v,bool rec[],vector<int> adj[]){
    vis[v]=true;
    rec[v]=true;
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        if(vis[*i]==false){
            if(iscyl(vis,*i,rec,adj))return true;
        }
        else if(rec[*i])return true;
    }
    rec[v]=false;
    return false;
}


bool isCyclic(int V, vector<int> adj[])
{
    bool vis[V];
    bool rec[V];
    for(int i=0;i<V;i++){
        vis[i]=false;
        rec[i]=false;
    }
    for(int i=0;i<V;i++){
        if(!vis[i]){
        if(iscyl(vis,i,rec,adj))return true;
        }
    }
    return false;
    
}


//-----------------is cyclic for undirected-----------------------//

bool iscyl(int s,bool vis[],vector<int> adj[],int parent){
    vis[s]=true;
    for(auto i=adj[s].begin();i!=adj[s].end();i++){
        if(!vis[*i]){
            if(iscyl(*i,vis,adj,s))return true;
        }
        else if(*i!=parent)return true;
    }
    return false;
}


bool isCyclic(vector<int> adj[], int V)
{
   bool vis[V];
   bool rec[V];
   for(int i=0;i<V;i++){
       vis[i]=false;
       rec[i]=false;
   }
   for(int i=0;i<V;i++){
       if(!vis[i])if(iscyl(i,vis,adj,-1))return true;
   }
   return false;
}

//--------dfs adjancy ----------//

int issafe(int n,int m,int i,int j){
    if(i<n&&i>=0&&j>=0&&j<m)return true;
    else return false;
}


void findis(vector<int>vis[],vector<int>A[],int x,int y,int n,int m){
    vis[x][y]=true;
    int rox[]={-1,-1,-1,0,0,1,1,1};
    int coly[]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<8;i++){
        if(issafe(n,m,x+rox[i],y+coly[i])&&A[x+rox[i]][y+coly[i]]&&!vis[x+rox[i]][y+coly[i]])findis(vis,A,x+rox[i],y+coly[i],n,m);
    }
}


int findIslands(vector<int> A[], int N, int M)
{
    
    vector<int> vis[N];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            vis[i].push_back(false);
        }
    }
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!vis[i][j]&&A[i][j]){
                findis(vis,A,i,j,N,M);
                cnt++;
            }
        }
        
    }
    return cnt;
}

//----------------------------mcolor problems-----------------------//

bool issafe(vector<int>adj[],vector<int>col,int o,int k){
    for(int i=0;i<adj[k].size();i++){
        int v=adj[k][i];
        if(v==k||col[v]==0)continue;
        if(o==col[v])return false;
    }
    return true;
}

int mcoloutil(vector<int>adj[],int m,int n,int s,vector<int>&col,vector<bool>vis){
    vis[s]=true;
    for(int c=1;c<=m;c++){
     if(issafe(adj,col,c,s)){
         col[s]=c;
         int rem=0;
         for(int i=0;i<adj[s].size();i++){
             int v=adj[s][i];
             if(vis[v])continue;
             rem=1;
             if(mcoloutil(adj,m,n,v,col,vis))return 1;
         } 
         if(!rem)return 1;
         col[s]=0;
     }   
        
    }
    return 0;
}


int mcolor(vector<int>adj[],int m,int n){
    vector<bool>vis(n+1,false);
	vector<int>col(n+1,0);
	int sol=1;
	for(int c=1;c<=n;c++){
	    if(col[c]==0){
	        sol=sol&mcoloutil(adj,m,n,c,col,vis);
	    }
	    
	}
	return sol;
}

//------------------------hamiltonian path ----------------//
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

