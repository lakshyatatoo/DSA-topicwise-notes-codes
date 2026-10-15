#include <bits/stdc++.h>
using namespace std;

// greedy but fails at decidng which side to insert the character, so we need to use dp
class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        int is = 0;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                is++;
                i++;
            }
        }
        return is;
    }
};

// memmoization
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
    int lps(string &s1, string &s2)
    {
        int n = s1.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return func(n, n, s1, s2, dp);
    }
    int minInsertions(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return s.size() - lps(s, t);
    }
};

// tabulation
class Solution
{
public:
    int lps(string &s1, string &s2)
    {
        int n = s1.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = 0;
        } // even tho declaration is already 0, we are doing this to make it more clear
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return s.size() - lps(s, t);
    }
};

// tabulation optimizatio
// same
