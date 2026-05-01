# https://leetcode.com/problems/all-paths-from-source-lead-to-destination/description/

'''
Given the edges of a directed graph where edges[i] = [ai, bi] indicates there is an edge between nodes ai and bi, and two nodes source and destination of this graph, determine whether or not all paths starting from source eventually, end at destination, that is:

At least one path exists from the source node to the destination node
If a path exists from the source node to a node with no outgoing edges, then that node is equal to destination.
The number of possible paths from source to destination is a finite number.
Return true if and only if all roads from source lead to destination.

 

Example 1:


Input: n = 3, edges = [[0,1],[0,2]], source = 0, destination = 2
Output: false
Explanation: It is possible to reach and get stuck on both node 1 and node 2.
Example 2:


Input: n = 4, edges = [[0,1],[0,3],[1,2],[2,1]], source = 0, destination = 3
Output: false
Explanation: We have two possibilities: to end at node 3, or to loop over node 1 and node 2 indefinitely.
Example 3:


Input: n = 4, edges = [[0,1],[0,2],[1,3],[2,3]], source = 0, destination = 3
Output: true
 

Constraints:

1 <= n <= 104
0 <= edges.length <= 104
edges.length == 2
0 <= ai, bi <= n - 1
0 <= source <= n - 1
0 <= destination <= n - 1
The given graph may have self-loops and parallel edges.
'''

class Solution:
    BLACK=2
    GRAY=1
    def recursive(self,source,destination,states):
        if states[source]!=0:
            return states[source]==Solution.BLACK
        if len(self.adj_list[source])==0:
            return source==destination
        states[source]=Solution.GRAY
        for next_node in self.adj_list[source]:
            if not self.recursive(next_node,destination,states):
                return False
        states[source]=Solution.BLACK
        return True

    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        self.adj_list=defaultdict(list)
        states=[0]*n
        self.cnt=0
        for i in range(len(edges)):
            self.adj_list[edges[i][0]].append(edges[i][1])
        return self.recursive(source,destination,states)
        
'''
Complexity Analysis

Time Complexity: Typically for an entire DFS over an input graph, it takes O(V+E) where V represents the number of vertices in the graph and likewise, 
E represents the number of edges in the graph. In the worst case E can be O(V^2) in case each vertex is connected to every other vertex in the graph. 
However even in the worst case, we will end up discovering a cycle very early on and prune the recursion tree. If we were to traverse the entire graph, then the complexity would be O(V 2) as the O(E) part would dominate. 
However, due to pruning and backtracking in case of cycle detection, we end up with an overall time complexity of O(V).

Space Complexity: O(V+E) where O(E) is occupied by the adjacency list and O(V) is occupied by the recursion stack and the color states.
'''