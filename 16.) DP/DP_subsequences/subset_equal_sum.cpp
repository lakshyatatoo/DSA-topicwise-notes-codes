#include <bits/stdc++.h>
using namespace std;

// memoi
class Solution
{
public:
    bool func(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return arr[0] == target;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool notTake = func(ind - 1, arr, target, dp);
        bool take = false;
        if (arr[ind] <= target)
            take = func(ind - 1, arr, target - arr[ind], dp);
        return dp[ind][target] = take || notTake;
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return func(arr.size() - 1, arr, sum, dp);
    }
};

// tabulation //cant understand the logic of this code
// say till i is this target possible
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        vector<vector<bool>> dp(arr.size(), vector<bool>(sum + 1, false));
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true; // bcz on i=0 we can make target= a[0];
        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if (arr[i] <= target)
                    take = dp[i - 1][target - arr[i]];
                dp[i][target] = take || notTake;
            }
        }
        return dp[n - 1][sum];
    }
};

// tabulaiton. space optimization
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        vector<bool> dp(sum + 1, false);
        int n = arr.size();
        dp[0] = true;
        dp[arr[0]] = true; // bcz on i=0 we can make target= a[0];
        for (int i = 1; i < n; i++)
        {
            vector<bool> curr(sum + 1, false);
            curr[0] = true;
            for (int target = 1; target <= sum; target++)
            {
                bool notTake = dp[target];
                bool take = false;
                if (arr[i] <= target)
                    take = dp[target - arr[i]];
                curr[target] = take || notTake;
            }
            dp = curr;
        }
        return dp[sum];
    }
};