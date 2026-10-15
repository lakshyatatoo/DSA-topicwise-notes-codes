#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution
{
public:
    int func(int ind, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return (target % coins[0] == 0);
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = 0 + func(ind - 1, target, coins, dp);
        int take = 0;
        if (coins[ind] <= target)
            take = 1 + func(ind, target - coins[ind], coins, dp);
        return dp[ind][target] = min(take, notTake);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = func(n - 1, amount, coins, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};

// tabulation
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
                dp[0][j] = j / coins[0];
            else
                dp[0][j] = 1e9;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int notTake = 0 + dp[i - 1][j];
                int take = 1e9;
                if (coins[i] <= j)
                    take = 1 + dp[i][j - coins[i]]; /// min coins to make up amount up till i-1
                // it takes the same i so it jsut checks in prev smae row value for the remaining amount after taking the coin
                dp[i][j] = min(take, notTake);
            }
        }
        int ans = dp[n - 1][amount];
        return ans >= 1e9 ? -1 : ans;
    }
};

// tabulation with space optimization prev and curr