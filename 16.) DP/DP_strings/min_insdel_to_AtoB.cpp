#include <bits/stdc++.h>
using namespace std;

// memoi
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
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return (n + m) - 2 * func(n, m, word1, word2, dp); // total length of both strings - 2*length of lcs
    }
};

// tabultion
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = 0;
        for (int j = 0; j < m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return (n + m) - 2 * dp[n][m];
    }
};