#include <bits/stdc++.h>
using namespace std;
// memoization
// pass target as below

//  using tabulation
class Solution
{
public:
    int countPartitions(vector<int> &arr, int diff)
    {
        int n = arr.size(), sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        int target = (sum - diff) / 2;
        if (sum - diff < 0 || (sum - diff) % 2 != 0)
            return 0;
        vector<vector<int>> dp(arr.size(), vector<int>((target + 1), 0));
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
//  use temp and dp singlularily