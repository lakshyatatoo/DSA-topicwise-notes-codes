#include <bits/stdc++.h>
using namespace std;

// problem statement -- transaction is capped at k

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
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 1, prices, dp, k);
    }
};
// memoization n*4
class Solution
{
public:
    int f(int i, int trno, vector<int> &prices, vector<vector<int>> &dp, int k)
    {
        if (trno == 2 * k || i == prices.size()) // all actions completed
            return 0;
        if (dp[i][trno] != -1)
            return dp[i][trno];
        if (trno % 2 == 0)
            return dp[i][trno] = max(-prices[i] + f(i + 1, trno + 1, prices, dp, k), f(i + 1, trno, prices, dp, k));
        else
            return dp[i][trno] = max(prices[i] + f(i + 1, trno + 1, prices, dp, k), f(i + 1, trno, prices, dp, k));
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, -1));
        return f(0, 0, prices, dp, k);
    }
};

// tabulation
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(k + 1, 0));
        // for (int j = 0; j <= 1; j++)//initailised everything by zero so no need to do this
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
            vector<vector<int>> temp(2, vector<int>(k + 1, 0));
            for (int j = 0; j <= 1; j++)
            {
                for (int l = 1; l <= k; l++)
                {
                    if (j)
                        temp[j][l] = max(-prices[i] + dp[0][l], dp[1][l]);
                    else
                        temp[j][l] = max(prices[i] + dp[1][l - 1], dp[0][l]);
                }
            }
            dp = temp;
        }

        return dp[1][k];
    }
};

// tabulation n*4
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = (2 * k) - 1; j >= 0; j--)
            {
                if (j % 2 == 0)
                    dp[i][j] = max(-prices[i] + dp[i + 1][j + 1], dp[i + 1][j]);
                else
                {
                    dp[i][j] = max(prices[i] + dp[i + 1][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0]; // first state of buy based on trno and index 0
    }
};

// space optmisation n*4
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(2 * k + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> temp(2 * k + 1, 0);
            for (int j = (2 * k) - 1; j >= 0; j--)
            {
                if (j % 2 == 0)
                    temp[j] = max(-prices[i] + dp[j + 1], dp[j]);
                else
                {
                    temp[j] = max(prices[i] + dp[j + 1], dp[j]);
                }
            }
            dp = temp;
        }
        return dp[0];
    }
};
