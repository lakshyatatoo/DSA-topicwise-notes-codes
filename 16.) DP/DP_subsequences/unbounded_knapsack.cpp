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
            return (W / wt[0] * val[0]);
        }
        if (dp[ind][W] != -1)
            return dp[ind][W];
        int notTake = func(ind - 1, W, val, wt, dp);
        int take = INT_MIN;
        if (wt[ind] <= W)
            take = val[ind] + func(ind, W - wt[ind], val, wt, dp);
        return dp[ind][W] = max(take, notTake);
    }
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        vector<vector<int>> dp(wt.size(), vector<int>(capacity + 1, -1));
        return func(wt.size() - 1, capacity, val, wt, dp);
    }
};

// tabulation can be done too
class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
        for (int i = wt[0]; i <= capacity; i++)
        {
            dp[0][i] = i / wt[0] * val[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= capacity; j++)
            {
                int notTake = dp[i - 1][j];
                int take = INT_MIN;
                if (wt[i] <= j)
                {
                    take = dp[i][j - wt[i]] + val[i];
                }
                dp[i][j] = max(notTake, take);
            }
        }
        return dp[n - 1][capacity];
    }
};

// tabulation optmised single arrray
class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = wt.size();
        vector<int> dp(capacity + 1, 0);
        for (int i = wt[0]; i <= capacity; i++)
        {
            dp[i] = (i / wt[0]) * val[0];
        }
        for (int i = 1; i < n; i++)
        {
            // vector<int> temp(capacity + 1, 0);
            for (int j = 0; j <= capacity; j++)
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
        return dp[capacity];
    }
};
