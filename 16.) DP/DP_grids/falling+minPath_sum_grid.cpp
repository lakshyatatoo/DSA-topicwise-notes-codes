#include <bits/stdc++.h>
using namespace std;
// memoir for min path sum
class Solution
{
public:
    int func(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid)
    {
        if (i == 0 && j == 0)
            return grid[i][j];
        if (i < 0 || j < 0)
            return 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = grid[i][j] + func(i - 1, j, dp, grid);
        int left = grid[i][j] + func(i, j - 1, dp, grid);
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && m == 1)
            return grid[0][0];
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n - 1, m - 1, dp, grid);
    }
};
// for simple left right we take up and left min here we need extra left diagonal and right diagonal as well so we take min of all three and return the answer
//  memoization
class Solution
{
public:
    int func(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &matrix)
    {
        if (j < 0 || j >= matrix[0].size())
            return 1e9;
        if (i == 0)
            return matrix[i][j];
        if (dp[i][j] != 1e9)
            return dp[i][j];
        int up = matrix[i][j] + func(i - 1, j, dp, matrix);
        int left = matrix[i][j] + func(i - 1, j - 1, dp, matrix);
        int right = matrix[i][j] + func(i - 1, j + 1, dp, matrix);
        return dp[i][j] = min(up, min(left, right));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 1)
            return *min_element(matrix[0].begin(), matrix[0].end());
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        int ans = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            func(n - 1, j, dp, matrix);
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};

// tabulation
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 1)
            return *min_element(matrix[0].begin(), matrix[0].end());
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        int ans = INT_MAX;
        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = 1e9, left = 1e9, right = 1e9, x = matrix[i][j];
                if (i >= 0)
                    up = x + dp[i - 1][j];
                if (i - 1 >= 0 && j - 1 >= 0)
                    left = x + dp[i - 1][j - 1];
                if (i - 1 >= 0 && j + 1 < m)
                    right = x + dp[i - 1][j + 1];
                dp[i][j] = min(up, min(left, right));
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// tabulation space optimised
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 1)
            return *min_element(matrix[0].begin(), matrix[0].end());
        vector<int> dp(m, 1e9);
        for (int j = 0; j < m; j++)
            dp[j] = matrix[0][j];
        for (int i = 1; i < n; i++)
        {
            vector<int> temp(m, 1e9);
            for (int j = 0; j < m; j++)
            {
                int up = 1e9, left = 1e9, right = 1e9, x = matrix[i][j];
                if (i >= 0)
                    up = x + dp[j];
                if (i - 1 >= 0 && j - 1 >= 0)
                    left = x + dp[j - 1];
                if (i - 1 >= 0 && j + 1 < m)
                    right = x + dp[j + 1];
                temp[j] = min(up, min(left, right));
            }
            dp = temp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
