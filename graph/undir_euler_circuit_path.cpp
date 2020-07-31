#include<bits/stdc++.h>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V)   {this->V = V; adj = new list<int>[V]; }
    ~Graph() { delete [] adj; }
    void addEdge(int v, int w);
    int isEulerian();
    bool isConnected();
    void DFSUtil(int v, bool visited[]);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
void test(Graph &g)
{
    int res = g.isEulerian();
    if (res == 0)
        cout << "0\n";    //none
    else if (res == 1)
        cout << "1\n";    //Euler path
    else
        cout << "2\n";    //Euler cycle
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int v,e;
		cin>> v>>e;
		Graph g1(v);
		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;
		g1.addEdge(a, b);
		}
		test(g1);
	}
    return 0;
}


bool Graph::isConnected() 
{ 
    // Mark all the vertices as not visited 
    bool visited[V]; 
    int i; 
    for (i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Find a vertex with non-zero degree 
    for (i = 0; i < V; i++) 
        if (adj[i].size() != 0) 
            break; 
  
    // If there are no edges in the graph, return true 
    if (i == V) 
        return true; 
  
    // Start DFS traversal from a vertex with non-zero degree 
    DFSUtil(i, visited); 
  
    // Check if all non-zero degree vertices are visited 
    for (i = 0; i < V; i++) 
       if (visited[i] == false && adj[i].size() > 0) 
            return false; 
  
    return true; 
} 
  
/* The function returns one of the following values 
   0 --> If grpah is not Eulerian 
   1 --> If graph has an Euler path (Semi-Eulerian) 
   2 --> If graph has an Euler Circuit (Eulerian)  */
int Graph::isEulerian() 
{ 
    // Check if all non-zero degree vertices are connected 
    if (isConnected() == false) 
        return 0; 
  
    // Count vertices with odd degree 
    int odd = 0; 
    for (int i = 0; i < V; i++) 
        if (adj[i].size() & 1) 
            odd++; 
  
    // If count is more than 2, then graph is not Eulerian 
    if (odd > 2) 
        return 0; 
  
    // If odd count is 2, then semi-eulerian. 
    // If odd count is 0, then eulerian 
    // Note that odd count can never be 1 for undirected graph 
    return (odd)? 1 : 2; 
} 