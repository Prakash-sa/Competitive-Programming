// https://leetcode.com/problems/possible-bipartition/

bool possibleBipartition(int N, vector<vector<int>> &dislikes)
{
    vector<vector<int>> g(N);
    for (int i = 0; i < dislikes.size(); i++)
    {
        g[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
        g[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
    }
    vector<int> color(N, -1);
    for (int i = 0; i < N; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int j = 0; j < g[cur].size(); j++)
                {
                    int tmp = g[cur][j];
                    if (color[tmp] == -1)
                    {
                        color[tmp] = 1 - color[cur];
                        q.push(tmp);
                    }
                    else if (color[tmp] == color[cur])
                        return false;
                }
            }
        }
    }
    return true;
}