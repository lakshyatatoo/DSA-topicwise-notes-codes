#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution
{
public:
    int f(int i, int choice, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (i >= prices.size())
            return 0;
        if (dp[i][choice] != -1)
            return dp[i][choice];
        if (choice == 1)
            return dp[i][choice] = max(-prices[i] + f(i + 1, 0, prices, dp), f(i + 1, 1, prices, dp));
        else
            return dp[i][choice] = max(prices[i] + f(i + 2, 1, prices, dp), f(i + 1, 0, prices, dp));
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};

// tabultion
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        dp[n + 1][0] = dp[n + 1][1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {

            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            dp[i][0] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
        }
        return dp[0][1];
    }
};

// tabulation with space optimization
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> old(2, 0);
        vector<int> mid(2, 0);
        vector<int> latest(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {

            latest[1] = max(-prices[i] + mid[0], mid[1]);
            latest[0] = max(prices[i] + old[1], mid[0]);
            old = mid;
            mid = latest;
        }
        return latest[1];
    }
};
