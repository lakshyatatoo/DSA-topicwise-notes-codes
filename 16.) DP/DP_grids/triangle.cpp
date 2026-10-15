#include <bits/stdc++.h>
using namespace std;

// memoization tle
class Solution
{
public:
    int func(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        if (i == n - 1)
            return triangle[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int d = triangle[i][j] + func(i + 1, j, dp, triangle);
        int dg = triangle[i][j] + func(i + 1, j + 1, dp,
                                       triangle);
        return dp[i][j] = min(d, dg);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(0, 0, dp, triangle);
    }
};

// tabulation
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int d = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }
};

// tabulation space optimization
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp(n, -1);
        for (int j = 0; j < n; j++)
        {
            dp[j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> temp(n, -1);
            for (int j = i; j >= 0; j--)
            {
                temp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
            dp = temp;
        }
        return dp[0];
    }
};