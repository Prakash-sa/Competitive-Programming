#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];


long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}

//----------------------------------------------------------------

int solve(int N, vector<vector<int> > &bridges) {
    vector<vector<pair<int,int>>> g(N+1);
    for(auto& bridge: bridges){
        g[bridge[0]].push_back(make_pair(bridge[2], bridge[1]));
        g[bridge[1]].push_back(make_pair(bridge[2], bridge[0]));
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;//minheap
    unordered_set<int> visited;
    int totalCost = 0;
    q.push(make_pair(0,1));
    while(!q.empty()){
        auto curr = q.top();
        q.pop();
        if(visited.find(curr.second)!=visited.end()) continue;
        visited.insert(curr.second);
        
        totalCost += curr.first;
        for(auto& adj: g[curr.second]){
            if(visited.find(adj.second)!=visited.end()) continue;
            q.push(adj);
        }
    }
    return totalCost;
}
