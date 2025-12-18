# https://leetcode.com/problems/min-cost-to-connect-all-points/description/

'''
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Example 1
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
'''


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n=len(points)
        h=[(0,0)] # cost, point
        in_mst=[False]*n
        mst_cost=0
        edges_used=0
        while edges_used<n:
            w,curr_node=heappop(h)

            if in_mst[curr_node]:
                continue
            in_mst[curr_node]=True
            mst_cost+=w
            edges_used+=1
            for next_node in range(n):
                if not in_mst[next_node]:
                    next_w=abs(points[curr_node][0]-points[next_node][0])+abs(points[curr_node][1]-points[next_node][1])
                    heappush(h,(next_w,next_node))
        return mst_cost


# Complexity Analysis
# If N is the number of points in the input array.
# Time complexity: O(N^2*log(N)).
# Space complexity: O(N^2).

'''

Although the min-heap method is often used to implement Prim's algorithm (as it's fairly easy to understand), due to its use of a heap to store the edges, its time complexity is suboptimal.
Thus, we will present a more efficient way of implementing Prim's algorithm, which eliminates the use of min-heap to find the next lowest-weighted edge.

In this approach, we use one minDist array, where minDist[i] stores the weight of the smallest weighted edge to reach the i 
th
  node from any node in the current tree.
We will iterate over the minDist array and greedily pick the node that is not in the MST and has the smallest edge weight. We will add this node to the MST, and for all of its neighbors, we will try to update the value in minDist.
We will repeat this process until all nodes are part of the MST.

'''