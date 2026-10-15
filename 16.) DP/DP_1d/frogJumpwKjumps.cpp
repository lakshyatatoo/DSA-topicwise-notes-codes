#include <bits/stdc++.h>
using namespace std;

// memoization recursion
class Solution
{
private:
    int mem(int i, vector<int> &dp, vector<int> &height, int k)
    {
        if (i == 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int mnSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = mem(i - j, dp, height, k) + abs(height[i] - height[i - j]);
                mnSteps = min(mnSteps, jump);
            }
            else
                break;
        }
        return dp[i] = mnSteps;
    }

public:
    int minCost(vector<int> &height, int k)
    {
        int n = height.size();
        vector<int> dp(n, -1);
        return mem(n - 1, dp, height, k);
    }
};

// tabulation
class Solution
{

public:
    int minCost(vector<int> &height, int k)
    {
        int n = height.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            int steps = INT_MAX;
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    int jump = dp[i - j] + abs(height[i] - height[i - j]);
                    steps = min(steps, jump);
                }
            }
            dp[i] = steps;
        }
        return dp[n - 1];
    }
};