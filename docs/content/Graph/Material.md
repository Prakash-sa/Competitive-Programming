Static Connectivity

If the entire graph is provided upfront in the problem (for example, this problem directly provides the grid through a 2D array grid), and we are then asked queries about connectivity (such as whether there exists a path from the start to the end), this is referred to as static connectivity.

The opposite concept is dynamic connectivity, where graph updates and connectivity queries are interleaved. In other words, after a connectivity query, the graph may still be modified. For example, if this problem included multiple queries where each query modifies a position in grid and then checks whether a valid path exists, with modifications persisting across queries, then it would be considered a dynamic connectivity problem.

For static connectivity problems, depth-first search, breadth-first search, and union-find can generally be used. These methods are conceptually similar, and the main challenge lies in constructing the graph, specifically determining which pairs of nodes should be connected.

Once the graph is constructed, we can easily determine whether two nodes are connected using any of these approaches.

In this solution, we focus on the Union-Find method. We treat each cell as a node in the graph, and define edges based on direct reachability between adjacent cells. Here, "direct reachability" means that a cell can move directly to one of its neighboring cells (up, down, left, or right).

For example, a cell with value 1 represents a street connecting the left and right cells, while a cell with value 3 connects the left and bottom cells. Therefore, if a cell with value 1 is to the left of a cell with value 3, these two cells are directly reachable. We can use Union-Find to maintain these relationships.

However, Union-Find operates on one-dimensional indices, while our grid is two-dimensional. Therefore, we map each cell (x,y) to a unique integer ID using the formula:
id=x×n+y
where n is the number of columns. This mapping ensures that each cell corresponds to a unique node in the Union-Find structure.
