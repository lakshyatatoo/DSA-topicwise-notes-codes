#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution
{
public:
    int func(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (wt[ind] <= W)
                return val[ind];
            else
                return 0;
        }
        if (dp[ind][W] != -1)
            return dp[ind][W];
        int nottake = func(ind - 1, W, val, wt, dp);
        int take = INT_MIN;
        if (wt[ind] <= W)
            take = val[ind] + func(ind - 1, W - wt[ind], val, wt, dp);
        return dp[ind][W] = max(take, nottake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return func(n - 1, W, val, wt, dp);
    }
};

// tabulation

class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int i = wt[0]; i <= W; i++)
        {
            dp[0][i] = val[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                int notTake = dp[i - 1][j];
                int take = INT_MIN;
                if (wt[i] <= j)
                {
                    take = dp[i - 1][j - wt[i]] + val[i];
                }
                dp[i][j] = max(notTake, take);
            }
        }
        return dp[n - 1][W];
    }
};

// tabulation optimization

class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        vector<int> dp(W + 1, 0);
        for (int i = wt[0]; i <= W; i++)
        {
            dp[i] = val[0];
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> temp(W + 1, 0);
            for (int j = 1; j <= W; j++)
            {
                int notTake = dp[j];
                int take = INT_MIN;
                if (wt[i] <= j)
                {
                    take = dp[j - wt[i]] + val[i];
                }
                temp[j] = max(notTake, take);
            }
            dp = temp;
        }
        return dp[W];
    }
};

// single array optimization
class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        vector<int> dp(W + 1, 0);
        for (int i = wt[0]; i <= W; i++)
        {
            dp[i] = val[0];
        }
        for (int i = 1; i < n; i++)
        {
            // vector<int> temp(W + 1, 0);
            for (int j = W; j >= 0; j--)
            {
                int notTake = dp[j];
                int take = INT_MIN;
                if (wt[i] <= j)
                {
                    take = dp[j - wt[i]] + val[i];
                }
                dp[j] = max(notTake, take);
            }
        }
        return dp[W];
    }
};