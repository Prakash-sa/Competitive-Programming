# https://leetcode.com/problems/network-delay-time/description/

'''
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
'''

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        if not (1<=k<=n):
            return -1

        adj=[[] for _ in range(n+1)]

        for u,v, w in times:
            adj[u].append((v,w))
        
        h=[(0,k)]

        dis=[math.inf]*(n+1)
        dis[k]=0

        while h:
            t,u=heappop(h)
            if t!=dis[u]:
                continue

            for v,w in adj[u]:
                nt=t+w
                if nt<dis[v]:
                    dis[v]=nt
                    heappush(h,(nt,v))
        max_dist=max(dis[1:])
        return -1 if math.isinf(max_dist) else int(max_dist)


# Complexity Analysis
# Here N is the number of nodes and E is the number of total edges in the given network.
# Time complexity: O(N+ElogN)
# Dijkstra's Algorithm takes O(ElogN). Finding the minimum time required in signalReceivedAt takes O(N).
# The maximum number of vertices that could be added to the priority queue is E. Thus, push and pop operations on the priority queue take O(logE) time. The value of E can be at most N⋅(N−1). Therefore, O(logE) is equivalent to O(logN 2 ) which in turn equivalent to O(2⋅logN). Hence, the time complexity for priority queue operations equals O(logN).
# Although the number of vertices in the priority queue could be equal to E, we will only visit each vertex only once. If we encounter a vertex for the second time, then currNodeTime will be greater than signalReceivedAt[currNode], and we can continue to the next vertex in the priority queue. Hence, in total E edges will be traversed and for each edge, there could be one priority queue insertion operation.
# Hence, the time complexity is equal to O(N+ElogN).

# Space complexity: O(N+E)
# Building the adjacency list will take O(E) space. Dijkstra's algorithm takes O(E) space for priority queue because each vertex could be added to the priority queue N−1 time which makes it N∗(N−1) and O(N 2) is equivalent to O(E). signalReceivedAt takes O(N) space.
