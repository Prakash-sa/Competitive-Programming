//https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1



bool isPossible(bool graph[101][101],int color[],int N,int col,int node){
    for(int k=0;k<N;k++){
        if(k!=node && graph[node][k]==1 && color[k]==col) return false;
    }
    return true;
}

bool solve(bool graph[101][101],int m,int N,int color[],int node){
    if(node==N)
        return true;
        
    // traverse onto diff color recursively
    for(int i=1;i<=m;i++){  
        if(isPossible(graph,color,N,i,node)){
            color[node]=i;
            if(solve(graph,m,N,color,node+1)) return true;
            color[node]=0;
        }
            
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N];
    memset(color,0,sizeof color);
    if(solve(graph,m,N,color,0)) return true;
    return false;
}
