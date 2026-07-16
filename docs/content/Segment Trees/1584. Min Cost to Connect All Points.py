# https://leetcode.com/problems/min-cost-to-connect-all-points/description/


"""
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Example 1:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Example 2:
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

Constraints:
1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.
"""


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        h = [(0, 0)]  # cost, point
        in_mst = [False] * n
        mst_cost = 0
        edges_used = 0
        while edges_used < n:
            w, curr_node = heappop(h)

            if in_mst[curr_node]:
                continue
            in_mst[curr_node] = True
            mst_cost += w
            edges_used += 1
            for next_node in range(n):
                if not in_mst[next_node]:
                    next_w = abs(points[curr_node][0] - points[next_node][0]) + abs(
                        points[curr_node][1] - points[next_node][1]
                    )
                    heappush(h, (next_w, next_node))
        return mst_cost

"""
Complexity Analysis

If N is the number of points in the input array.

Time complexity: O(N^2⋅log(N)).
In the worst-case, we push/pop N⋅(N−1)/2≈N^2 edges of our graph in the heap. Each push/pop operation takes O(log(N^2))≈log(N) time.
Thus, the overall time complexity is O(N^2 ⋅log(N)).

Space complexity: O(N^2).
In the worst-case, we push N⋅(N−1)/2≈N^2 edges into the heap.
We use an array inMST of size N to mark which nodes are included in MST.
Thus, the overall space complexity is O(N^2+N)≈O(N^2).
"""

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        mst_cost = 0
        edges_used = 0

        # Track nodes which are visited.
        in_mst = [False] * n

        min_dist = [math.inf] * n
        min_dist[0] = 0

        while edges_used < n:
            curr_min_edge = math.inf
            curr_node = -1

            # Pick least weight node which is not in MST.
            for node in range(n):
                if not in_mst[node] and curr_min_edge > min_dist[node]:
                    curr_min_edge = min_dist[node]
                    curr_node = node

            mst_cost += curr_min_edge
            edges_used += 1
            in_mst[curr_node] = True

            # Update adjacent nodes of current node.
            for next_node in range(n):
                weight = abs(points[curr_node][0] - points[next_node][0]) + abs(
                    points[curr_node][1] - points[next_node][1]
                )

                if not in_mst[next_node] and min_dist[next_node] > weight:
                    min_dist[next_node] = weight

        return mst_cost

'''
Complexity Analysis
If N is the number of points in the input array.

Time complexity: O(N^2).
We pick all N nodes one by one to include in the MST. Picking each node takes O(N) time and after picking a node, we iterate over all of its adjacent nodes, which also takes O(N) time.
Thus, the overall time complexity is O(N⋅(N+N))=O(N^2).
Space complexity: O(N).

We use two arrays each of size N, inMST and minDist.
Thus, the overall space complexity is O(N+N)=O(N).
'''
