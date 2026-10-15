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
            if (target % coins[0] == 0)
                return 1;
            else
                return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = func(ind - 1, target, coins, dp);
        int take = 0;
        if (coins[ind] <= target)
            take = func(ind, target - coins[ind], coins, dp);
        return dp[ind][target] = take + notTake;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return func(n - 1, amount, coins, dp);
    }
};

// tabulation
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        int gcd = coins[0];
        for (int i = 1; i < n; i++)
        {
            gcd = __gcd(gcd, coins[i]);
        }
        if (amount % gcd != 0)
            return 0;
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));
        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                long long notTake = dp[i - 1][j];
                long long take = 0;
                if (coins[i] <= j)
                    take = dp[i][j - coins[i]]; /// min coins to make up amount up till i-1
                                                // it takes the same i so it jsut checks in prev smae row value for the remaining amount after taking the coin
                dp[i][j] = (take >= INT_MAX - notTake)
                               ? INT_MAX
                               : take + notTake;
            }
        }
        return dp[n - 1][amount];
    }
};