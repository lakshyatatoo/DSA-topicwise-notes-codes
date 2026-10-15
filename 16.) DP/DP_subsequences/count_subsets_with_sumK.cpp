#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution
{
public:
    int func(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return 1;
        }
        if (ind == 0)
        {
            if (arr[0] == target)
                return 1;
            else
                return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = func(ind - 1, target, arr, dp);
        int take = 0;
        if (arr[ind] <= target)
            take = func(ind - 1, target - arr[ind], arr, dp);
        return dp[ind][target] = take + notTake;
    }
    int perfectSum(vector<int> &arr, int target)
    {
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
        return func(arr.size() - 1, target, arr, dp);
    }
};

// tabulation
class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, 0));
        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        if (arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (arr[i] <= j)
                    take = dp[i - 1][j - arr[i]];
                dp[i][j] = take + notTake;
            }
        }
        return dp[n - 1][target];
    }
};

// tabulation space optimization
class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> dp(target + 1, 0);
        if (arr[0] == 0)
            dp[0] = 2;
        else
            dp[0] = 1;
        if (arr[0] != 0 && arr[0] <= target)
            dp[arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            vector<int> curr(target + 1, 0);
            for (int j = 0; j <= target; j++)
            {
                int notTake = dp[j];
                int take = 0;
                if (arr[i] <= j)
                    take = dp[j - arr[i]];
                curr[j] = take + notTake;
            }
            dp = curr;
        }
        return dp[target];
    }
};
