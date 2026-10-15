#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution
{
public:
    int f(int i, int choice, vector<int> &prices, vector<vector<int>> &dp, int fee)
    {
        if (i == prices.size())
            return 0;
        if (dp[i][choice] != -1)
            return dp[i][choice];
        if (choice == 1)
            return dp[i][choice] = max(-prices[i] - fee + f(i + 1, 0, prices, dp, fee), f(i + 1, 1, prices, dp, fee));
        else
            return dp[i][choice] = max(prices[i] + f(i + 1, 1, prices, dp, fee), f(i + 1, 0, prices, dp, fee));
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp, fee);
    }
};

// tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][1] = max(-prices[i] - fee + dp[i + 1][0], dp[i + 1][1]);
            dp[i][0] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
        }
        return dp[0][1];
    }
};

// tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> dp(2, 0);
        dp[0] = 0, dp[1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> temp(2, 0);
            temp[1] = max(-prices[i] - fee + dp[0], dp[1]);
            temp[0] = max(prices[i] + dp[1], dp[0]);
            dp = temp;
        }
        return dp[1];
    }
};
