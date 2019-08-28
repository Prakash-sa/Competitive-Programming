
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< lli,lli> pll;
typedef map< lli,lli> mll;
typedef map< int,int> mii;


vector <int> adj[100];
    bool visited[100];

    void dfs(int s) {
        visited[s] = true;
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
             dfs(adj[s][i]);
        }
    }

    void initialize() {
        for(int i = 0;i < 100;++i)
         visited[i] = false;
    }

    int main() {
        int nodes, edges, x, y, connectedComponents = 0;
        cin >> nodes;                       //Number of nodes
        cin >> edges;                       //Number of edges
        for(int i = 0;i < edges;++i) {
         cin >> x >> y;     
     //Undirected Graph 
         adj[x].push_back(y);                   //Edge from vertex x to vertex y
         adj[y].push_back(x);                   //Edge from vertex y to vertex x
        }

        int k;
        cin>>k;
        initialize();                           //Initialize all nodes as not visited

       
      //  dfs(k);

        int cnt=0;
        for(int i = 1;i <= nodes;++i) {
         if(visited[i] == false)     {
             cnt++;
             dfs(i);
             //connectedComponents++;
         }
        }
        cout<<cnt<<endl;

        //cout << "Number of connected components: " << connectedComponents << endl;
        return 0;
    }

