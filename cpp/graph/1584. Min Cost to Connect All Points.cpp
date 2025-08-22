/*
https://www.youtube.com/watch?v=f7JOBJIC-NA&ab_channel=NeetCode

https://leetcode.com/problems/min-cost-to-connect-all-points/

Minimum spanning tree


Prims algorithm

Min heap

*/




class Solution {
    
    
public:
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size(), res = 0, i = 0, connected = 0;
        vector<bool> visited(n);
        priority_queue<pair<int, int>> pq;
        while (++connected < n) {
            visited[i] = true;
            for (int j = 0; j < n; ++j){
                if (!visited[j])
                    pq.push({-(abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1])), j});
            }
            while (visited[pq.top().second]){
                pq.pop();
            }
            res -= pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return res;
    }
};
