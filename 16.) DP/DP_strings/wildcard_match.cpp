#include <bits/stdc++.h>
using namespace std;

// greedy approach see once
//  memoi version
class Solution
{
public:
    bool func(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return true;
        if (i == 0 && j > 0)
            return false;
        if (i > 0 && j == 0)
        {
            for (int x = 0; x <= i - 1; x++)
            {
                if (a[x] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if ((a[i - 1] == b[j - 1]) | (a[i - 1] == '?'))
            return dp[i][j] = func(i - 1, j - 1, a, b, dp);
        if (a[i - 1] == '*')
            return dp[i][j] = func(i - 1, j, a, b, dp) || func(i, j - 1, a, b, dp);
        return false;
    }
    bool isMatch(string s, string p)
    {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return func(n, m, p, s, dp);
    }
};

// tabulation
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
            dp[0][j] = false;
        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int x = 0; x <= i - 1; x++)
            {
                if (p[x] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if ((p[i - 1] == s[j - 1]) || (p[i - 1] == '?'))
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};

// tabulation optimisation by dp temp
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = p.size();
        int m = s.size();
        vector<int> dp(m + 1, -1);
        dp[0] = true;
        for (int j = 1; j <= m; j++)
            dp[j] = false;
        for (int i = 1; i <= n; i++)
        {
            vector<int> temp(m + 1, -1);
            bool flag = true;
            for (int x = 0; x <= i - 1; x++)
            {
                if (p[x] != '*')
                {
                    flag = false;
                    break;
                }
                if (!flag)
                    break;
            }
            temp[0] = flag;
            for (int j = 1; j <= m; j++)
            {
                if ((p[i - 1] == s[j - 1]) || (p[i - 1] == '?'))
                    temp[j] = dp[j - 1];
                else if (p[i - 1] == '*')
                    temp[j] = dp[j] || temp[j - 1];
                else
                    temp[j] = false;
            }
            dp = temp;
        }
        return dp[m];
    }
};