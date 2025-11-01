# Graph

## Problems 

- Hard
1. https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

2. https://leetcode.com/problems/shortest-path-visiting-all-nodes/submissions/

3. https://leetcode.com/problems/reconstruct-itinerary/

4. https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/


# Notes

- BFS only works for unweighted graphs. For weighted graphs, we'll need Dijkstra's algorithm.
- Bellman Ford won't work if the cycle is negative weight cycle.
- For negative edge cycles, we need Bellman-Ford's algorithm. Again this algorithm is single source shortest path algorithm. 
- If we need to find out distance from each nodes to all other nodes, we'll need Floyd-Warshall's algorithm.


# Minimum Obstacle removal to reach Corner

- Use bfs with deque and dp.
- If distance is less push at front otherwise push at back.


# Topological Sorting

- [Kahns Algo](https://www.youtube.com/watch?v=73sneFXuTEg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=14)
- [Prims](https://www.youtube.com/watch?v=mJcZjjKzeqk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=25)
- DFS + Stack
- Kahns Algorithm with indegree
- Directed Acyclic Graph

1. Course Schedule

2. Alien Dictionary

3. Directed Graph Cyclic



# Dijkastra

- Min heap(Priority Queue) with greater array condition(mat[p][q]+w<dist[p][q]).

1. Min Cost Path



# Binary tree camera

- Use dfs


# Critical Connections in a Network

- [Articulation Point](https://www.youtube.com/watch?v=j1QDfU21iZk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=30)
- [Tarjan's Algo](https://www.youtube.com/watch?v=qrAub5z8FeA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29)
- Use articulation point




# Smallest String with swaps

- Union Find



# Min Cost to connect all Points

- Minimum spanning tree(Prims Algorithm)


# Bipartite 

- [Video](https://www.youtube.com/watch?v=-vu34sct1g8&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=10)
- Use bfs from 0 to N-1 colors.



# Detect Cycle

1. Undirected Graph

- Use dfs
- If the node is visited, and is not parent then it is cyclic.


2. Directed Graph

- Use dfs
- Making recursive calls for the adjacent vertices and return true if any back edge is found.
- We can also use the Kahns Topological sorting.



# Euler Circuit

- If the graph is connected.
- If the inward is equal to outward.


# Hamiltonian Path

- Worst case complexity of using DFS and backtracking is O(N!).
- Time complexity of the dp algorithm is O(2^n n^2).



# Is Bridge

- Remove the edge and use dfs.
or 
- Use Articulation Point, The condition for an edge (u, v) to be a bridge is, “low[v] > disc[u]”. The value low[v] indicates earliest visited vertex reachable from subtree rooted with v. 

# Bridges in Graph

- [Tarjan's Algo](https://www.youtube.com/watch?v=qrAub5z8FeA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29)
- 



# Kosaraju Algo(Strongly Connected Component)

- [Video](https://www.youtube.com/watch?v=R6uoSjZ2imo&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=28)
- Only for Directed Graph
- Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack. In the above graph, if we start DFS from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0. 
- Reverse directions of all arcs to obtain the transpose graph. 
- One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v. In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by one popped from stack).


# Redundant Connection

- Use union find method.
- If both the x and y parent are same then return that link.



# Snake Ladder

- Use bfs with iteration from s+1 to min(s+6,30).

```
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
```

# Water Connection

- Store the in and out degree.
- Run dfs for in_degree=0 and out_degree=1
- Store the start, end and distance during dfs.


# DSU

- [Video](https://www.youtube.com/watch?v=aBxjDBC4M1U)
- 


# Kurskal Algo

- [Video](https://www.youtube.com/watch?v=DMnDM_sxVig)
- Sort all the edges with weight and apply DSU with rank
