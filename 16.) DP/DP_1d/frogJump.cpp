#include <bits/stdc++.h>
using namespace std;

// memoi recursion
// tc: O(n) sc: O(n)
class Solution
{
private:
    int memoi(int i, vector<int> &dp, vector<int> &h)
    {
        if (i == 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int left = memoi(i - 1, dp, h) + abs(h[i - 1] - h[i]);
        int right = INT_MAX;
        if (i > 1)
            right = memoi(i - 2, dp, h) + abs(h[i - 2] - h[i]);
        return dp[i] = min(left, right);
    }

public:
    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n, -1);
        return memoi(n - 1, dp, height);
    }
};

// tabulation
class Solution
{
public:
    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int left = dp[i - 1] + abs(height[i] - height[i - 1]);
            int right = INT_MAX;
            if (i > 1)
            {
                right = dp[i - 2] + abs(height[i] - height[i - 2]);
            }
            dp[i] = min(left, right);
        }
        return dp[n - 1];
    }
};

// tabulation space optimization
class Solution
{
public:
    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n, -1);
        int prev1 = 0;
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int left = prev1 + abs(height[i] - height[i - 1]);
            int right = INT_MAX;
            if (i > 1)
            {
                right = prev2 + abs(height[i] - height[i - 2]);
            }
            prev2 = prev1;
            prev1 = min(left, right);
        }
        return prev1;
    }
};
