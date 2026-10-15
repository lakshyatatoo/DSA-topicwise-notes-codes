#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution
{
public:
    int func(int ind, int target, vector<int> &price, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return target * price[0];
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = 0 + func(ind - 1, target, price, dp);
        int take = 0;
        if ((ind + 1) <= target)
            take = price[ind] + func(ind, target - (ind + 1), price, dp);
        return dp[ind][target] = max(take, notTake);
    }
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return func(n - 1, n, price, dp);
    }
};

// tabulation
class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = j * price[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int notTake = 0 + dp[i - 1][j];
                int take = 0;
                if ((i + 1) <= j)
                    take = price[i] + dp[i][j - (i + 1)];
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n - 1][n];
    }
};

// tabultion space optmisiation
// cna be doen using temp dp

// tabulation singel array optimisation
// similar to unbounded knapsack problem
// we know it uses back values so a single array sufices
class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> dp(n + 1, 0);
        for (int j = 0; j <= n; j++)
        {
            dp[j] = j * price[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int notTake = 0 + dp[j];
                int take = 0;
                if ((i + 1) <= j)
                    take = price[i] + dp[j - (i + 1)];
                dp[j] = max(take, notTake);
            }
        }
        return dp[n];
    }
};