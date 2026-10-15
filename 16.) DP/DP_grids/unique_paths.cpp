#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution
{
public:
    int func(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = func(i - 1, j, dp);
        int left = func(i, j - 1, dp);
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1, n - 1, dp);
    }
};

// tabulation
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                int up = i > 0 ? dp[i - 1][j] : 0;
                int left = j > 0 ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};

// tabulation space optimized
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    temp[j] = 1;
                else
                {
                    int up = i > 0 ? dp[j] : 0;
                    int left = j > 0 ? temp[j - 1] : 0;
                    temp[j] = up + left;
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};