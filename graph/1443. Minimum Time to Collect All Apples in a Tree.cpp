/*
Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices.
You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.
The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi.
Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.
*/

class Solution
{
    vector<vector<int>> adjList;

    int dfs(vector<bool> &hasApple, int node, int d, int prev)
    {
        int result = 0, tmp;
        for (int &i : adjList[node])
        {
            if (i != prev)
            {
                tmp = dfs(hasApple, i, d + 1, node);
                if (tmp)
                {
                    result += tmp - d;
                }
            }
        }
        return result || hasApple[node] ? result + d : 0;
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        adjList.resize(n);
        for (auto &e : edges)
        {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        return dfs(hasApple, 0, 0, -1) * 2;
    }
};