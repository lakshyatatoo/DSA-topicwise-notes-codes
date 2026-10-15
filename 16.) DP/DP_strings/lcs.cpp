#include <bits/stdc++.h>
using namespace std;

// memoization
// right shifted index by 1
class Solution
{
public:
    int func(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1[i - 1] == text2[j - 1])
            return dp[i][j] = 1 + func(i - 1, j - 1, text1, text2, dp);
        else
            return dp[i][j] = max(func(i - 1, j, text1, text2, dp), func(i, j - 1, text1, text2, dp));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return func(n, m, text1, text2, dp);
    }
};

// tabulation
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = 0;
        for (int j = 0; j < m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

// tabulation with space optimization
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m + 1);
        for (int j = 0; j < m; j++)
            dp[j] = 0;

        for (int i = 1; i <= n; i++)
        {
            vector<int> temp(m + 1);
            temp[0] = 0;
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    temp[j] = 1 + dp[j - 1];
                else
                    temp[j] = max(dp[j], temp[j - 1]);
            }
            dp = temp;
        }
        return dp[m];
    }
};