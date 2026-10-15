#include <bits/stdc++.h>
using namespace std;

// memoi
class Solution
{
public:
    bool func(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return arr[0] == target;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool notTake = func(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
        {
            take = func(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = take || notTake;
    }
    bool canPartition(vector<int> &nums)
    {
        int total = 0;
        for (int num : nums)
        {
            total += num;
        }
        if (total % 2 != 0)
        {
            return false;
        }
        int target = total / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return func(nums.size() - 1, target, nums, dp);
    }
};

// tabulation
class Solution
{
public:
    bool func(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return arr[0] == target;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool notTake = func(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
        {
            take = func(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = take || notTake;
    }
    bool canPartition(vector<int> &nums)
    {
        int total = 0;
        for (int num : nums)
        {
            total += num;
        }
        if (total % 2 != 0)
        {
            return false;
        }
        int target = total / 2;
        int n = nums.size();
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (nums[i] <= j)
                {
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = take || notTake;
            }
        }
        return dp[n - 1][target];
    }
};

// tabulation space optimisation
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int total = 0;
        for (int num : nums)
        {
            total += num;
        }
        if (total % 2 != 0)
        {
            return false;
        }
        int target = total / 2;
        int n = nums.size();
        vector<bool> dp(target + 1);

        dp[0] = true;
        if (nums[0] <= target)
            dp[nums[0]] = true; // bcz on i=0 we can make target= a[0];
                                // because a singl elemnt can exceed target
        for (int i = 1; i < n; i++)
        {
            vector<bool> curr(target + 1, false);
            curr[0] = true;
            for (int j = 1; j <= target; j++)
            {
                bool notTake = dp[j];
                bool take = false;
                if (nums[i] <= j)
                    take = dp[j - nums[i]];
                curr[j] = take || notTake;
            }
            dp = curr;
        }
        return dp[target];
    }
};