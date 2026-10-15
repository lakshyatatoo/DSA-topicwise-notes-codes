#include <bits/stdc++.h>
using namespace std;

// tabulation
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int n = stones.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += stones[i];
        int x = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(x + 1, false));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (stones[0] <= x)
            dp[0][stones[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= x; j++)
            {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (stones[i] <= j)
                {
                    take = dp[i - 1][j - stones[i]];
                }
                dp[i][j] = take || notTake;
            }
        }
        int mini = 1e9;
        for (int i = 0; i <= x; i++)
        {
            if (dp[n - 1][i] == true)
            {
                // int s1 = i;
                // int s2 = sum - i;
                mini = min(mini, abs(sum - 2 * i));
            }
        }
        return mini;
    }
};

// optimisiation can be done using prev and curr