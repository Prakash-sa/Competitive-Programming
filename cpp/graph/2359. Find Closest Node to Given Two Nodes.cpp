//https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. 
If there is no outgoing edge from i, then edges[i] == -1.
You are also given two integers node1 and node2.
Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized.
If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.
Note that edges may contain cycles.
 

Example 1:

Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
*/


class Solution {
public:
    int closestMeetingNode(vector<int>& e, int node1, int node2) {
        int res = -1, min_dist = INT_MAX;
        vector<int> m1(e.size(), -1), m2(e.size(), -1);
        for (int i = node1, dist = 0; i != -1 && m1[i] == -1; i = e[i])
            m1[i] = dist++;
        for (int i = node2, dist = 0; i != -1 && m2[i] == -1; i = e[i]) {
            m2[i] = dist++;
            if (m1[i] >= 0 && max(m1[i], m2[i]) <= min_dist) {
                res = max(m1[i], m2[i]) == min_dist ? min(i, res) : i;
                min_dist = max(m1[i], m2[i]);
            }
        }
        return res;
    }
};

