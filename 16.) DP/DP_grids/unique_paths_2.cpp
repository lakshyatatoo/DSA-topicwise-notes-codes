#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution
{
public:
    int func(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = func(i - 1, j, dp, obstacleGrid);
        int left = func(i, j - 1, dp, obstacleGrid);
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0] == 1)
            return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n - 1, m - 1, dp, obstacleGrid);
    }
};

// tabulation
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0] == 1)
            return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

// tabulation space optimized
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0] == 1)
            return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<int> dp(m, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    temp[j] = 0;
                }
                else if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                }
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[j];
                    if (j > 0)
                        left = temp[j - 1];
                    temp[j] = up + left;
                }
            }
            dp = temp;
        }
        return dp[m - 1];
    }
};