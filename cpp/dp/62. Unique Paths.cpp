// https://leetcode.com/problems/unique-paths/

/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

//

/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.



Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right


Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

*/

// Below is the bfs solution:-

class Solution
{
    vector<vector<int>> dp;
    int n, m;
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;
        if (n == 1 && m == 1)
            return 1;
        dp.resize(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dp[0][0] = 1;
        while (!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            int x = tmp.first;
            int y = tmp.second;
            for (int i = 0; i < 2; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || obstacleGrid[xx][yy] == 1)
                    continue;

                if (dp[xx][yy] == 0)
                    q.push({xx, yy});
                dp[xx][yy] += dp[x][y];
            }
        }
        return dp[n - 1][m - 1];
    }
};
// Below is the dp solution:-

class Solution
{

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;
        if (n == 1 && m == 1)
            return 1;
        vector<int> dp(m, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else if (j > 0)
                    dp[j] += dp[j - 1];
            }
        }
        return dp[m - 1];
    }
};