int Solution::solve(int N, vector<vector<int> > &bridges) {
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
