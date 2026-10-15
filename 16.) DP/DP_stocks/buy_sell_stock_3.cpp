#include <bits/stdc++.h>
using namespace std;

// problem statement -- transaction is capped at 2
// also works in greedy approach but we will use dp here
// memoization
class Solution
{
public:
    int f(int i, int choice, vector<int> &prices, vector<vector<vector<int>>> &dp, int cap)
    {
        if (cap == 0 || i == prices.size())
            return 0;
        if (dp[i][choice][cap] != -1)
            return dp[i][choice][cap];
        if (choice)
            return dp[i][choice][cap] = max(-prices[i] + f(i + 1, 0, prices, dp, cap), f(i + 1, 1, prices, dp, cap));
        else
            return dp[i][choice][cap] = max(prices[i] + f(i + 1, 1, prices, dp, cap - 1), f(i + 1, 0, prices, dp, cap));
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, prices, dp, 2);
    }
};

// tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                dp[i][j][0] = 0;
            }
        }
        for (int i = 0; i <= 1; i++)
        {
            for (int j = 0; j <= 2; j++)
                dp[n][i][j] = 0;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    if (j)
                        dp[i][j][k] = max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
                    else
                        dp[i][j][k] = max(prices[i] + dp[i + 1][1][k - 1], dp[i + 1][0][k]);
                }
            }
        }
        return dp[0][1][2];
    }
};

// space optimization tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(3, 0));
        // for (int j = 0; j <= 1; j++)//initailised everything by zero so
        // {
        //     dp[j][0] = 0;
        // }

        // for (int i = 0; i <= 1; i++)
        // {
        //     for (int j = 0; j <= 2; j++)
        //         dp[i][j] = 0; // why beca
        // }
        for (int i = n - 1; i >= 0; i--)
        {
            vector<vector<int>> temp(2, vector<int>(3, 0));
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    if (j)
                        temp[j][k] = max(-prices[i] + dp[0][k], dp[1][k]);
                    else
                        temp[j][k] = max(prices[i] + dp[1][k - 1], dp[0][k]);
                }
            }
            dp = temp;
        }

        return dp[1][2];
    }
};