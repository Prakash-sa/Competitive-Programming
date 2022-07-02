## Problems 

- Hard
1. https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

2. https://leetcode.com/problems/shortest-path-visiting-all-nodes/submissions/

3. https://leetcode.com/problems/reconstruct-itinerary/

4. https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/


# Notes

- BFS only works for unweighted graphs. For weighted graphs, we'll need Dijkstra's algorithm.
- For negative edge cycles, we need Bellman-Ford's algorithm. Again this algorithm is single source
shortest path algorithm. 
- If we need to find out distance from each nodes to all other nodes, we'll need Floyd-
Warshall's algorithm.


# Minimum Obstacle removal to reach Corner

- Use bfs with deque and dp.
- If distance is less push at front otherwise push at back.


# Topological Sorting

- DFS + Stack
- Kahns Algorithm with indegree

1. Course Schedule

2. Alien Dictionary

3. Directed Graph Cyclic



# Dijkastra

- Min heap(Priority Queue) with greater array condition(mat[p][q]+w<dist[p][q]).

1. Min Cost Path



# Binary tree camera

- Use dfs


# Critical Connections in a Network

- Use articulation point



# Smallest String with swaps

- Union Find



# Min Cost to connect all Points

- Minimum spanning tree(Prims Algorithm)


# Bipartite 

- Use bfs for 0 to N-1 colors.



# Detect Cycle

1. Undirected Graph

- Use dfs
- if the node is visited and is not parent then it is cyclic.


2. Directed Graph

- Use dfs
- Making recursive calls for the adjacent vertices and return true if any back edge is found.
- We can also use the Kahns Topological sorting.



# Euler Circuit

- If the graph is connected.
- If the inward is equal to outward.


# Hamiltonian Path




# Is Bridge

- Remove the edge and use dfs.
- 



# Kosaraju Algo




# Redundant Connection

- Use union find method.
- If both the x and y parent are same then return that link.




# Snake Ladder

- Use bfs with iteration from s+1 to min(s+6,30).

    int s=q.front();
    q.pop();
    if(s==30)break;
    for(int i=s+1;i<=s+6&&i<=30;i++){
        if(a[i]==-1){
            dis[i]=min(dis[i],dis[s]+1);
            q.push(i);
        }
        else {
            dis[a[i]]=min(dis[a[i]],dis[s]+1);
            q.push(a[i]);
        }
    }


# Water Connection

- Store the in and out degree.
- Run dfs for in_degree=0 and out_degree=1
- Store the start, end and distance during dfs.
 