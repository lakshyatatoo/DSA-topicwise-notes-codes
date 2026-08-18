#include <bits/stdc++.h>
using namespace std;

// memoisation

class Solution
{
private:
    int memoi(int i, int start, int end, vector<int> &nums, vector<int> &dp)
    {
        if (i == start)
            return nums[i];
        if (i < start)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int pick = nums[i] + memoi(i - 2, start, end, nums, dp);
        int notPick = memoi(i - 1, start, end, nums, dp);
        return dp[i] = max(pick, notPick);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n, -1);
        int first = memoi(n - 2, 0, n - 2, nums, dp);
        dp.assign(n, -1);
        int second = memoi(n - 1, 1, n - 1, nums, dp);
        return max(first, second);
    }
};

// tabulation
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for (int i = 1; i < n - 1; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        int first = dp[n - 2];
        dp.assign(n, -1);
        dp[1] = nums[1];
        for (int i = 2; i < n; i++)
        {
            int pick = nums[i];
            if (i > 2)
                pick += dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        int second = dp[n - 1];
        return max(first, second);
    }
};

// tabulation space optmised
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int prev = nums[0], prev2 = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int notPick = prev;
            prev2 = prev, prev = max(pick, notPick);
        }
        int first = prev;

        ////
        prev = nums[1], prev2 = 0;
        for (int i = 2; i < n; i++)
        {
            int pick = nums[i];
            if (i > 2)
                pick += prev2;
            int notPick = prev;
            prev2 = prev, prev = max(pick, notPick);
        }
        int second = prev;
        return max(first, second);
    }
};
