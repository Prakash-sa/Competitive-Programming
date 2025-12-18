# Graph Algorithms Cheat Sheet

This directory is organised by technique (BFS/DFS, shortest paths, MST, DSU, topo sort, etc.). Use the guide below to jump to the right approach during contests and interviews.

## Core toolkits
- **Traversal basics (`dfs & bfs`)**
  - BFS for unweighted shortest path / level order (multi-source BFS folder adds simultaneous starts).
  - DFS for component counting, cycle detection, Euler paths (iterative implementations help avoid recursion depth issues).
  - Watch: [Graph Traversal (William Fiset)](https://www.youtube.com/watch?v=bIA8HEEUxZI)

- **Shortest paths**
  - `Dijkastra Algo` folder: priority queue + adjacency lists; complexity `O((V + E) log V)`. Mention that weights must be non-negative.
  - `Bellman Ford`: handles negative weights in `O(V * E)`; detect negative cycles.
  - `Floyd Warshall`: all-pairs shortest path in `O(V^3)`, good when `V <= 400`.
  - `Minimum Cost to Make at Least One Valid Path` uses 0-1 BFS with deque; push front for zero-cost edges.
  - Watch:
    - [Dijkstra's Algorithm (Abdul Bari)](https://www.youtube.com/watch?v=XB4MIexjvY0)
    - [Bellman-Ford Explained (Tushar Roy)](https://www.youtube.com/watch?v=FtN3BYH2Zes)
    - [Floyd-Warshall Algorithm (William Fiset)](https://www.youtube.com/watch?v=YbY8cVwWAvw)
    - [0-1 BFS Trick (Errichto)](https://www.youtube.com/watch?v=4uUGxZXoR5o)

- **Minimum spanning tree**
  - `Minimum Spanning Tree` folder: Kruskal (sort edges + DSU) and Prim (min-heap). Complexity `O(E log V)`.
  - Interview note: compare when Kruskal vs Prim is preferred (dense vs sparse graphs).
  - Watch:
    - [Kruskal's MST (Abdul Bari)](https://www.youtube.com/watch?v=71UQH7Pr9kU)
    - [Prim's MST (William Fiset)](https://www.youtube.com/watch?v=0nK5GkL7ik8)

- **Disjoint Set Union (DSU)**
  - Used in `Disjoint Set Union`, `Redundant Connection`, `Smallest String with Swaps`, `Min Cost to Connect All Points`.
  - KPI: union by size + path compression yields nearly O(alpha(n)) per op.
  - Watch: [Disjoint Set Union (Errichto)](https://www.youtube.com/watch?v=VHRhJWacxis)

- **Topological sorting**
  - `Topological Sort` folder: Kahn's algorithm (BFS + indegree) and DFS stack approach.
  - Applied in `Course Schedule`, `Alien Dictionary`, cycle detection within DAG prerequisites.
  - Watch: [Kahn's Algorithm (Striver)](https://www.youtube.com/watch?v=73sneFXuTEg)

- **Bridges, articulation points, SCC**
  - `Critical Connections in a Network`, `Bridges`, `Is Bridge` implement Tarjan's DFS with discovery/low arrays.
  - `Kosaraju` folder covers strongly connected components in directed graphs (two-pass DFS).
  - Watch:
    - [Tarjan's Algorithm for Bridges (William Fiset)](https://www.youtube.com/watch?v=2kREIkF9UAs)
    - [Kosaraju's Algorithm (Tushar Roy)](https://www.youtube.com/watch?v=R6uoSjZ2imo)

- **Special patterns**
  - `Flood Fill` / `Multi Source BFS` for grids.
  - `Cycle detection` distinguishes directed vs undirected handling.
  - `Water Connection`, `Snake and Ladder` show graph modelling of real-world puzzles.
  - Watch: [Flood Fill & Grid BFS (freeCodeCamp)](https://www.youtube.com/watch?v=Hea7qT2DxpY)

## Quick decision matrix

| Task | Preferred technique | Complexity |
|------|---------------------|------------|
| Unweighted shortest path | BFS / multi-source BFS | `O(V + E)` |
| Weighted shortest path w/out negatives | Dijkstra + heap | `O((V + E) log V)` |
| Weighted path with negatives | Bellman-Ford (single source), Floyd-Warshall (all-pairs) | `O(VE)` / `O(V^3)` |
| Detect cycle (directed) | DFS with recursion stack or Kahn | `O(V + E)` |
| Detect cycle (undirected) | DFS with parent tracking or DSU | `O(V + E)` |
| Minimum spanning tree | Kruskal + DSU or Prim + heap | `O(E log V)` |
| Bridges / articulation | Tarjan's algorithm | `O(V + E)` |
| Eulerian path/circuit | Degree checks + DFS/Hierholzer | `O(V + E)` |

## Featured hard problems
1. [Minimum Cost to Make at Least One Valid Path in a Grid](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)
2. [Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/)
3. [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/)
4. [Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)

## Concept notes
- BFS covers unweighted shortest paths; for weighted edges you need Dijkstra or better.
- Bellman-Ford fails when a negative cycle is reachable; use it precisely to detect those cycles.
- For graphs with negative edges but no negative cycles, Bellman-Ford handles single-source shortest paths.
- To get all-pairs distances, switch to Floyd-Warshall or repeated Dijkstra depending on density.

## Pattern deep dives

### Minimum Obstacle Removal to Reach Corner
- Use a deque-based BFS (0-1 BFS): push front when the new cost is equal, push back when cost increases.
- Maintain distance array; update if the new cost is smaller before pushing.
- Watch: [0-1 BFS Trick (Errichto)](https://www.youtube.com/watch?v=4uUGxZXoR5o)

### Topological sorting toolkit
- DFS + stack or Kahn's algorithm with indegree counts solve DAG ordering.
- Problems: Course Schedule, Alien Dictionary, detecting cycles in directed graphs.
- Watch:
  - [Kahn's Algorithm (Striver)](https://www.youtube.com/watch?v=73sneFXuTEg)
  - [Prim's Algorithm refresher (take U forward)](https://www.youtube.com/watch?v=mJcZjjKzeqk)

### Dijkstra and variants
- Always pair with a min-heap priority queue; relax edges when `dist[u] + w < dist[v]`.
- Apply to Min Cost Path and other weighted shortest-path problems without negative edges.
- Watch: [Dijkstra's Algorithm (Abdul Bari)](https://www.youtube.com/watch?v=XB4MIexjvY0)

### Binary Tree Cameras (tree DP intuition)
- Treat the tree as an undirected graph; run DFS with states (has camera / covered / needs camera).
- Watch: [Binary Tree Cameras (NeetCode)](https://www.youtube.com/watch?v=2kLIa1M3yI0) *(supplementary)*

### Critical Connections and Bridges
- Use Tarjan's algorithm with discovery and low-link arrays to flag articulation points or bridges.
- Watch:
  - [Articulation Points (Striver)](https://www.youtube.com/watch?v=j1QDfU21iZk)
  - [Tarjan's Algorithm (Striver)](https://www.youtube.com/watch?v=qrAub5z8FeA)

### Union-Find staples
- Smallest String With Swaps and Redundant Connection rely on DSU with path compression.
- Watch: [Union Find (aBxjDBC4M1U)](https://www.youtube.com/watch?v=aBxjDBC4M1U)

### Minimum cost to connect points
- Model as MST (Prim or Kruskal). Complexity `O(n^2 log n)` with adjacency matrix + Prim, or `O(E log V)` with edges.
- Watch: [Kruskal Explained (take U forward)](https://www.youtube.com/watch?v=DMnDM_sxVig)

### Bipartite graphs
- Try BFS/DFS two-colouring from each unvisited node.
- Watch: [Check Bipartite (Striver)](https://www.youtube.com/watch?v=-vu34sct1g8)

### Cycle detection
- Undirected: DFS with parent tracking; encountering a visited non-parent node signals a cycle.
- Directed: DFS with recursion stack or Kahn; any back-edge or leftover node indicates a cycle.

### Euler circuit checklist
- Graph must be connected (ignoring isolated vertices) and in-degree equals out-degree for every node.

### Hamiltonian path complexity
- Brute force DFS/backtracking is O(n!). DP with bitmask improves to O(2^n n^2).

### Bridges and articulation review
- Condition for edge (u, v) to be bridge: `low[v] > disc[u]`.
- Watch: [Tarjan's Algorithm (Striver)](https://www.youtube.com/watch?v=qrAub5z8FeA)

### Kosaraju strongly connected components
- Steps: DFS order stack, reverse graph, DFS following stack order.
- Watch: [Kosaraju's Algorithm (Tushar Roy)](https://www.youtube.com/watch?v=R6uoSjZ2imo)

### Snake and Ladder BFS snippet
```cpp
int s = q.front();
q.pop();
if (s == 30) break;
for (int i = s + 1; i <= s + 6 && i <= 30; i++) {
    if (a[i] == -1) {
        dis[i] = min(dis[i], dis[s] + 1);
        q.push(i);
    } else {
        dis[a[i]] = min(dis[a[i]], dis[s] + 1);
        q.push(a[i]);
    }
}
```

### Water connection sketch
- Compute in/out degree for each node; run DFS from sources (`in_degree == 0` and `out_degree == 1`) to record start/end/length pipes.

### DSU and Kruskal references
- DSU playlist: [Disjoint Set (aBxjDBC4M1U)](https://www.youtube.com/watch?v=aBxjDBC4M1U)
- Kruskal overview: [Kruskal's Algorithm (take U forward)](https://www.youtube.com/watch?v=DMnDM_sxVig)

## Interview reminders
- Always mention constraints to justify algorithm choice (e.g. why `Floyd-Warshall` is acceptable or not).
- When using heaps, explain the tuple order to avoid comparator pitfalls in Python.
- For grid problems, spell out how you linearise `(r, c)` indices or keep visited states (include wall-breaking or weight state if applicable).
- Stress how DSU handles union-find in near constant time and keeps cycle detection trivial.
- Walk the interviewer through example adjacency lists and the visitation order - clarity increases confidence.

## Additional resources
- [Graph Theory Playlist (William Fiset)](https://www.youtube.com/playlist?list=PLzMcBGfZo4-nhWva-6OVh1yKWHBs4o_tv)
- [Striver's Graph Series](https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw)
