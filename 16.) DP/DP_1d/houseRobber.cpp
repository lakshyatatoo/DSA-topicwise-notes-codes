#include <bits/stdc++.h>
using namespace std;

// memoization
// n,n
class Solution
{
private:
    int memoi(int i, vector<int> &arr, vector<int> &dp)
    {
        if (i == 0)
            return arr[i];
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int pick = arr[i] + memoi(i - 2, arr, dp);
        int notPick = memoi(i - 1, arr, dp);
        return dp[i] = max(pick, notPick);
    }

public:
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return memoi(n - 1, arr, dp);
    }
};

// tabulation
class Solution
{
private:
public:
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = arr[0];
        int prev = arr[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = arr[i];
            if (i > 1)
                pick += prev2;
            int notPick = prev;
            prev = max(pick, notPick);
            prev2 = prev;
        }
        return prev;
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int notPick = prev;
            prev2 = prev;
            prev = max(pick, notPick);
        }
        return prev;
    }
};