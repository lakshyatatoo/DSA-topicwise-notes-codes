#include <bits/stdc++.h>
using namespace std;

// greedy
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int buy = prices[0];
        int mp = 0;
        for (int i = 1; i < n; i++)
        {
            int p = prices[i] - buy;
            if (p >= 0)
            {
                mp += p;
                buy = prices[i];
            }
            else
            {
                buy = min(buy, prices[i]);
            }
        }
        return mp;
    }
};

// memoi version
class Solution
{
public:
    int f(int i, int choice, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (i == prices.size())
            return 0;
        if (dp[i][choice] != -1)
            return dp[i][choice];
        if (choice == 1)
            return dp[i][choice] = max(-prices[i] + f(i + 1, 0, prices, dp), f(i + 1, 1, prices, dp));
        else
            return dp[i][choice] = max(prices[i] + f(i + 1, 1, prices, dp), f(i + 1, 0, prices, dp));
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};

// tabulatiion
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int c = 0; c <= 1; c++)
            {
                if (c == 1)
                {
                    dp[i][c] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                }
                else
                {
                    dp[i][c] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

// tabulation with space optimization
// variable optimisaion is smae just we are using two variable instead of 2d array so dont think about it too much
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(2, 0);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> temp(2, 0);
            for (int c = 0; c <= 1; c++)
            {
                if (c == 1)
                {
                    temp[c] = max(-prices[i] + dp[0], dp[1]);
                }
                else
                {
                    temp[c] = max(prices[i] + dp[1], dp[0]);
                }
            }
            dp = temp;
        }
        return dp[1];
    }
};
